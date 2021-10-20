/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:54:27 by nschumac          #+#    #+#             */
/*   Updated: 2021/06/18 15:37:50 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, unsigned long len)
{
	char				*substr;
	unsigned int		count;

	count = 0;
	substr = 0;
	substr = (char *)malloc(len + 1);
	if (!substr || !s || start >= ft_strlen(s))
		return (substr);
	while (count < len && s[start + count] != '\0')
	{
		substr[count] = s[start + count];
		count++;
	}
	substr[count] = '\0';
	return (substr);
}
