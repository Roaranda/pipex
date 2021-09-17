/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaranda <roaranda@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:57:39 by roaranda          #+#    #+#             */
/*   Updated: 2020/08/27 18:49:55 by roaranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_all(char const *s1, char const *s2, char const *s3,
					char const *s4)
{
	size_t		len[4];
	size_t		size;
	size_t		tmp;
	char		*ret;

	if (!s1 || !s2 || !s3 || !s4)
		return (NULL);
	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2);
	len[2] = ft_strlen(s3);
	len[3] = ft_strlen(s4);
	size = len[0] + len[1] + len[2] + len[3];
	ret = (char *)ft_calloc((size + 1), sizeof(char));
	if (!ret)
		return (NULL);
	tmp = ft_strlcpy(ret, s1, len[0] + 1);
	tmp += ft_strlcat(ret + tmp, s2, len[1] + 1);
	tmp += ft_strlcat(ret + tmp, s3, len[2] + 1);
	tmp += ft_strlcat(ret + tmp, s4, len[3] + 1);
	return (ret);
}
