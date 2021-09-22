#include "./libft/include/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
** check_args function splits both commands into the command and its arguments;
** in example: "ls -la" into "ls" and "-la", checks the existence of the
** command in /usr/bin/ folder and if the binary has executable permission
** for the user that is running the process.
*/

int check_args(int argc, char *argv[])
{
    char **splited_cmd[2];
    char *path_cmd[2];

    if (argc != 5)
    {
        printf("Incorrect number of arguments\n");
        return (-1);
    }
    splited_cmd[0] = ft_split(argv[2], ' ');
    splited_cmd[1] = ft_split(argv[3], ' ');
    if (!splited_cmd[0]|| !splited_cmd[1])
        return (-1);
    path_cmd[0] = ft_strjoin("/usr/bin/", splited_cmd[0][0]);
    path_cmd[1] = ft_strjoin("/usr/bin/", splited_cmd[1][0]);
    if (access(path_cmd[0], X_OK) < 0)
    {
        perror("First command error: ");
        return (-1);
    }
    if (access(path_cmd[1], X_OK) < 0)
    {
        perror("Second command error: \n");
        return (-1);
    }
    ft_free(2, &path_cmd[0], &path_cmd[1]);
    return (1);
}

void child_one(char *argv[], char *envp[], int pipefd[])
{
    char **splited_cmd;
    char *path_cmd;
    int fd;

    close(pipefd[0]);
    splited_cmd = ft_split(argv[2], ' ');
    path_cmd = ft_strjoin("/usr/bin/", splited_cmd[0]);
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening input file for reading: ");
        exit(EXIT_FAILURE);
    }
    dup2(fd, STDIN_FILENO);
    dup2(pipefd[1], STDOUT_FILENO);
    execve(path_cmd, splited_cmd, envp);
    exit(EXIT_FAILURE);
}

void child_two(char *argv[], char *envp[], int pipefd[])
{
    char **splited_cmd;
    char  *path_cmd;
    int fd;

    close(pipefd[1]);
    splited_cmd = ft_split(argv[3], ' ');
    path_cmd = ft_strjoin("/usr/bin/", splited_cmd[0]);
    fd = open(argv[4], O_WRONLY | O_CREAT, 644);
    if (fd < 0)
    {
        perror("Error opening file for writting: ");
        exit(EXIT_FAILURE);
    }
    dup2(pipefd[0], STDIN_FILENO);
    dup2(fd, STDOUT_FILENO);
    execve(path_cmd, splited_cmd, envp);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[], char *envp[])
{
    int   pipe_fd[2];
    int   status;
    pid_t pid[2];
 
    if (check_args(argc, argv) < 0)
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
    {
        perror("Child 2 failed: ");
        return (-1);
    }
    else if (pid[1] == 0)
        child_two(argv, envp, pipe_fd);
    close(pipe_fd[0]);
    close(pipe_fd[1]);  
    waitpid(pid[0], &status, 0);
    waitpid(pid[1], &status, 0);
    return (1);
}