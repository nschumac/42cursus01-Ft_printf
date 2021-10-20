/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:54:48 by nschumac          #+#    #+#             */
/*   Updated: 2021/06/18 17:33:37 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlcpy(char *dest, const char *src, unsigned long n)
{
	unsigned long	count;

	if (!dest)
		return (0);
	count = 0;
	while (count + 1 < n && src[count])
	{
		dest[count] = src[count];
		count++;
	}
	if (n)
		dest[count] = '\0';
	return (ft_strlen(src));
}
