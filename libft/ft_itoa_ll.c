/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaranda <roaranda@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:51:59 by roaranda          #+#    #+#             */
/*   Updated: 2020/04/23 07:35:16 by roaranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_ll(long long int n)
{
	char			*str;
	int				len;
	long long int	num;

	len = ft_nbrlen(n);
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		num = -n;
	else
		num = n;
	while (num >= 10)
	{
		len--;
		str[len] = (num % 10) + 48;
		num = num / 10;
	}
	len--;
	str[len] = num + 48;
	if (len != 0)
		str[len - 1] = '-';
	return (str);
}
