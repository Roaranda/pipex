/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaranda <roaranda@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 05:51:43 by roaranda          #+#    #+#             */
/*   Updated: 2020/08/25 16:24:32 by roaranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *s)
{
	size_t	len;
	char	*rev;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (len < 2)
		return (ft_strdup(s));
	rev = (char *)ft_calloc(len + 1, sizeof(char));
	if (!rev)
		return (NULL);
	i = 0;
	j = len - 1;
	while (j >= 0)
	{
		rev[i] = s[j];
		i++;
		j--;
	}
	return (rev);
}
