/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaranda <roaranda@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 08:18:42 by roaranda          #+#    #+#             */
/*   Updated: 2020/11/17 11:38:02 by roaranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
		//i = (s[i] ? i + 1 : i);
		i = ternary(s[i], i);
*/

int	ternary(char c, int i)
{
	if (c != '\0')
		return (i + 1);
	else
		return (i);
}

static int	ft_num_frag(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
		i = ternary(s[i], i);
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	j;
	int		z;

	if (!s)
		return (NULL);
	ptr = (char **)(ft_calloc(ft_num_frag(s, c) + 1, sizeof(char *)));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	z = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = i;
			while (s[i] && s[i] != c)
				i++;
			ptr[z++] = ft_substr(s, j, i - j);
		}
		i = ternary(s[i], i);
	}
	return (ptr);
}
