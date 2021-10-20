/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:53:16 by nschumac          #+#    #+#             */
/*   Updated: 2021/06/16 19:03:06 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, unsigned long n)
{
	unsigned long	count;

	count = 0;
	while (count < n)
	{
		*((unsigned char *)str + count) = (unsigned char)c;
		count++;
	}
	return (str);
}
