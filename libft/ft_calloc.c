/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:58:54 by nschumac          #+#    #+#             */
/*   Updated: 2021/06/18 17:02:05 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(unsigned int num, unsigned int size)
{
	void				*buf;
	unsigned int		count;

	count = 0;
	buf = 0;
	buf = malloc(num * size);
	if (!buf)
		return (0);
	while (count < num * size)
	{
		*((unsigned char *)buf + count) = 0;
		count++;
	}
	return (buf);
}
