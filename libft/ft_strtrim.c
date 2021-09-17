/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaranda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:09:55 by roaranda          #+#    #+#             */
/*   Updated: 2019/12/11 17:12:29 by roaranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_searchbg(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (j == ft_strlen(set))
			break ;
		j = 0;
		i++;
	}
	return (i);
}

static size_t	ft_searchend(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;

	i = (size_t)(ft_strlen(s1) - 1);
	j = 0;
	while (i > 0)
	{
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (j == ft_strlen(set))
			break ;
		j = 0;
		i--;
	}
	i = i + 1;
	return (i);
}

/*
** Before norminette v3 there was this ternary:
** [ len = (start <= end ? end - start : 0); ] 
** instead the second if/else block in this function.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	size_t		len;
	char		*str;

	if (!s1)
		return (NULL);
	start = ft_searchbg(s1, set);
	end = ft_searchend(s1, set);
	if (start <= end)
		len = end - start;
	else
		len = 0;
	str = ft_substr(s1, start, len);
	return (str);
}
