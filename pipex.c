/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaranda <roaranda@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:16:10 by roaranda          #+#    #+#             */
/*   Updated: 2021/09/25 17:40:08 by roaranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
** search_cmd_path() is the crucial auxiliary function in pipex. It is called
** when the argument for a command has not been passed as an absolute path
** like "/bin/cat". This function will get the PATH env variable using 
** ft_getenv() and split it into paths. 
** Then it will test each path with the given cmd passed as argument to
** check its existence and if it counts with executable permission for the user
** that is running pipex.
** This function does not need to free() each allocated pointer since this 
** function is called from the child processes that will be wiped out by the
** execev() function so memory leaks will be wiped out as well.
**
** ---------------------------- A note for main() ----------------------------
** Since both forked procceses use "exec" functions there is no need to nest
** if/elses as is usual when using fork() because exec will wipe the
** forked-child process so the code under the child function call will never be
** executed by any of the child procesess.
**
** --------------- Explanation for each child process function ---------------
** The child one function will substitute his STDIN fd for the input file fd and 
** his STDOUT fd for the write end of the pipe using dup2().
** Child two will substitue his STDIN fd for the read end of the pipe and his
** STDOUT for the fd of the output file using dup2().
*/

char	*search_cmd_path(char *cmd, char *envp[])
{
	char	**splited_path;
	char	*env_path;
	char	*cmd_path;
	int		i;

	env_path = ft_getenv(envp, "PATH");
	splited_path = ft_split(env_path, ':');
	i = 0;
	while (splited_path[i])
	{
		cmd_path = ft_strjoin_all(splited_path[i], "/", cmd, "");
		if (access(cmd_path, X_OK) == 0)
			break ;
		i++;
	}
	return (cmd_path);
}

void	child_one(char *argv[], char *envp[], int pipefd[])
{
	char	**splited_cmd;
	char	*path_cmd;
	int		fd;
	int		err;

	close(pipefd[0]);
	splited_cmd = ft_split(argv[2], ' ');
	if (access(splited_cmd[0], X_OK) == 0)
		path_cmd = splited_cmd[0];
	else
		path_cmd = search_cmd_path(splited_cmd[0], envp);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening input file: ");
		exit(EXIT_FAILURE);
	}
	dup2(fd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	err = execve(path_cmd, splited_cmd, envp);
	if (err < 0)
		perror(ft_strjoin("Error command not found ", splited_cmd[0]));
	exit(EXIT_FAILURE);
}

void	child_two(char *argv[], char *envp[], int pipefd[])
{
	char	**splited_cmd;
	char	*path_cmd;
	int		fd;
	int		err;

	close(pipefd[1]);
	splited_cmd = ft_split(argv[3], ' ');
	if (access(splited_cmd[0], X_OK) == 0)
		path_cmd = splited_cmd[0];
	else
		path_cmd = search_cmd_path(splited_cmd[0], envp);
	fd = open(argv[4], O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
	{
		perror("Error opening output file: ");
		exit(EXIT_FAILURE);
	}
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	err = execve(path_cmd, splited_cmd, envp);
	if (err < 0)
		perror(ft_strjoin("Error command not found ", splited_cmd[0]));
	exit(EXIT_FAILURE);
}

int	check_args(int argc)
{
	if (argc != 5)
	{
		printf("Incorrect number of arguments\n");
		printf("Pipex usage:\n./pipex file1 cmd1 cmd2 file2\n");
		return (-1);
	}
	return (1);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		pipe_fd[2];
	int		status;
	pid_t	pid[2];

	if (check_args(argc) < 0)
		return (-1);
	pipe(pipe_fd);
	pid[0] = fork();
	if (pid[0] < 0)
	{
		perror("Child 1 failed: ");
		return (-1);
	}
	else if (pid[0] == 0)
		child_one(argv, envp, pipe_fd);
	pid[1] = fork();
	if (pid[1] < 0)
		return (-1);
	else if (pid[1] == 0)
		child_two(argv, envp, pipe_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid[0], &status, 0);
	waitpid(pid[1], &status, 0);
	return (1);
}
