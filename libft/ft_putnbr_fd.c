/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaranda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:02:41 by roaranda          #+#    #+#             */
/*   Updated: 2019/12/09 11:32:49 by roaranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		a;
	long int	num;

	num = (long int)n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	if (num >= 10)
	{
		ft_putnbr_fd((num / 10), fd);
		a = num % 10 + 48;
		write(fd, &a, 1);
	}
	else
	{
		a = num % 10 + 48;
		write(fd, &a, 1);
	}
}
