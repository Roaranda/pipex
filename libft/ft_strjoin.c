/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaranda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:48:31 by roaranda          #+#    #+#             */
/*   Updated: 2019/12/10 17:16:26 by roaranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		size;
	char		*s1s2;
	int			i;
	int			j;

	if (!s1 || !s2)
		return (NULL);
	size = (size_t)ft_strlen(s1) + (size_t)ft_strlen(s2);
	s1s2 = (char *)malloc((size + 1) * sizeof(char));
	if (s1s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s1s2[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s1s2[i + j] = s2[j];
		j++;
	}
	s1s2[i + j] = '\0';
	return (s1s2);
}
