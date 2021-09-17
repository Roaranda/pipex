/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaranda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:01:36 by roaranda          #+#    #+#             */
/*   Updated: 2019/12/10 15:18:27 by roaranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char *str)
{
	if (*str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		return (1);
	else
		return (0);
}

static int	ft_sign(const char *str)
{
	if ((*str == '-')
		&& (*(str + 1) >= '0' && *(str + 1) <= '9'))
	{
		return (-1);
	}
	else if (*str == '+'
		&& (*(str + 1) >= '0' && *(str + 1) <= '9'))
	{
		return (1);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	long int	i;
	int			sign;

	i = 0;
	sign = 1;
	while ((ft_isspace(str) == 1) || (*str == '+') || (*str == '-')
		|| (*str >= '0' && *str <= '9'))
	{
		while (ft_isspace(str) == 1)
			str++;
		if (*str == '-' || *str == '+')
		{
			sign = ft_sign(str);
			str++;
		}
		while (*str >= '0' && *str <= '9')
		{
			i = (i + (*str - 48)) * 10;
			str++;
		}
		i = (i / 10) * sign;
		return (i);
	}
	return (0);
}
