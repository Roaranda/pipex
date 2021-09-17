/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaranda <roaranda@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 13:28:11 by roaranda          #+#    #+#             */
/*   Updated: 2020/11/16 17:22:13 by roaranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This is a function that frees multiple pointers that are passed as arguments
** by reference, so each argument is actually the address of the pointer to be
** freed. I made this function to save multiple code lines in my C projects.
**
** The first argument must be the quantity of pointers to be freed.
** The objective of using the pass by reference instead the pass by value for
** every pointer is to set the pointer to NULL after the free.
** An example of calling to this function is "ft_free(2, &ptr1, &ptr2);"
*/

void	ft_free(unsigned int n, ...)
{
	va_list	ap;
	void	**p;
	int		i;

	i = n + 1;
	va_start(ap, n);
	while (--i > 0)
	{
		p = (void **)va_arg(ap, void *);
		if (*p != NULL)
		{
			free(*p);
			*p = NULL;
		}
	}
	va_end(ap);
	return ;
}
