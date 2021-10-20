/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:54:43 by nschumac          #+#    #+#             */
/*   Updated: 2021/06/18 17:33:26 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlcat(char *dst, const char *src, unsigned long n)
{
	unsigned long	count;
	unsigned long	dstlen;
	unsigned long	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	count = 0;
	if (n - 1 <= dstlen)
		return (srclen + n);
	while (count + dstlen + 1 < n)
	{
		dst[dstlen + count] = src[count];
		count++;
	}
	dst[dstlen + count] = '\0';
	return (dstlen + srclen);
}
