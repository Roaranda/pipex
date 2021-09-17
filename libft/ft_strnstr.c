/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaranda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:44:02 by roaranda          #+#    #+#             */
/*   Updated: 2019/12/05 20:33:29 by roaranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0' || !needle)
		return ((char *)(haystack));
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] == needle[j] && (i + j) < len
			&& haystack[i + j])
			j++;
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		j = 0;
		i++;
	}
	return (NULL);
}
