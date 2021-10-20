/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:53:20 by nschumac          #+#    #+#             */
/*   Updated: 2021/06/18 13:04:10 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, unsigned long n)
{
	unsigned long	count;
	unsigned char	*ptr1_buffer;
	unsigned char	*ptr2_buffer;

	ptr1_buffer = (unsigned char *)ptr1;
	ptr2_buffer = (unsigned char *)ptr2;
	count = 0;
	while (count < n)
	{
		if (*(ptr1_buffer + count)
			!= *(ptr2_buffer + count))
			return (*(ptr1_buffer + count) - *(ptr2_buffer + count));
		count++;
	}
	count--;
	return (*(ptr1_buffer + count) - *(ptr2_buffer + count));
}
