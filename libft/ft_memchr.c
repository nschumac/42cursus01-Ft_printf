/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:54:16 by nschumac          #+#    #+#             */
/*   Updated: 2021/06/16 19:33:33 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *ptr, int value, unsigned long n)
{
	unsigned long	count;

	count = 0;
	while (count < n)
	{
		if (*((unsigned char *)ptr + count) == (unsigned char)value)
			return ((unsigned char *)ptr + count);
		count++;
	}
	return (0);
}
