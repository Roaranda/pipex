/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaranda <roaranda@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 22:27:23 by roaranda          #+#    #+#             */
/*   Updated: 2020/04/27 17:27:12 by roaranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** After norminette v3 the ternary "ret = (exponent == 0) ? 1 : base;"
** was substituted by the first if/else block
*/

long long int	ft_pow(int base, int exponent)
{
	long long int	ret;

	if (exponent == 0)
		ret = 1;
	else
		ret = base;
	while (exponent-- > 1)
		ret *= base;
	return (ret);
}
