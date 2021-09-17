/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaranda <roaranda@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:09:33 by roaranda          #+#    #+#             */
/*   Updated: 2021/09/17 00:51:01 by roaranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function returns the value of the env variable passed as argument.
** First argument is the array of env variables as strings. That array has
** to be passed in the main as "char *envp[]" before the call to this function.
** ----------------------------------------------------------------------------
** HIW: the functions go through the array until strncmp matches the var_name
** with the first <len> characters of the enviroment variable, example "PATH"
** with "PATH=/home/dev/...". When it happens the value of the env var (part 
** of the string after '=') is exctracted using ft_substr and returned.
*/

char	*ft_getenv(char **envp, const char *var_name)
{
	int		i;
	size_t	len;
	char	*var_value;
	size_t	len_value;

	if (!var_name || !envp)
		return (NULL);
	i = 0;
	len = ft_strlen(var_name);
	i = 0;
	var_value = NULL;
	while ((envp[i] != NULL) && (var_value == NULL))
	{
		if (ft_strncmp(var_name, envp[i], len) == 0)
		{
			len_value = ft_strlen(envp[i]) - len;
			var_value = ft_substr(envp[i], len + 1, len_value);
			if (!var_value)
				return (NULL);
		}
		i++;
	}
	return (var_value);
}
