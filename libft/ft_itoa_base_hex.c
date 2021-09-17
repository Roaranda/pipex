/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaranda <roaranda@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 12:43:16 by roaranda          #+#    #+#             */
/*   Updated: 2020/08/25 16:25:01 by roaranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen_hex(long int n)
{
	int	len;

	if (n < 0)
	{
		len = 2;
		n = -n;
	}
	else
		len = 1;
	while (n > 15)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static char	hexchar(long int reminder)
{
	char	rem;

	if (reminder < 10)
		rem = reminder + 48;
	else if (reminder == 10)
		rem = 'A';
	else if (reminder == 11)
		rem = 'B';
	else if (reminder == 12)
		rem = 'C';
	else if (reminder == 13)
		rem = 'D';
	else if (reminder == 14)
		rem = 'E';
	else if (reminder == 15)
		rem = 'F';
	else
		rem = '\0';
	return (rem);
}

char	*ft_itoa_base_hex(long long int n)
{
	char	*str;
	int		len;

	len = ft_nbrlen_hex(n);
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		n = -n;
	while (n >= 16)
	{
		len--;
		str[len] = hexchar(n % 16);
		n = n / 16;
	}
	len--;
	str[len] = hexchar(n);
	if (len != 0)
		str[len - 1] = '-';
	return (str);
}
