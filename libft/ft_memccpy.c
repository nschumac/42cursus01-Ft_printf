/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:53:35 by nschumac          #+#    #+#             */
/*   Updated: 2021/06/18 16:19:18 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dest, const void *restrict src,
int c, unsigned long n)
{
	unsigned long	count;

	count = 0;
	while (count < n)
	{
		*((unsigned char *)dest + count) = *((unsigned char *)src + count);
		if (*((unsigned char *)src + count) == (unsigned char)c)
		{
			return ((unsigned char *)dest + count + 1);
		}
		count++;
	}
	return (0);
}
