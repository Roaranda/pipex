/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaranda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:15:16 by roaranda          #+#    #+#             */
/*   Updated: 2019/11/27 23:55:26 by roaranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	c = (char)c;
	i = 0;
	while (*s != 0)
	{
		i++;
		s++;
	}
	while (i > 0)
	{
		if (*s == c)
			break ;
		i--;
		s--;
	}
	if (*s == c)
		return ((char *)s);
	else
		return (NULL);
}
