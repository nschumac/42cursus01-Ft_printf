/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:07:41 by nschumac          #+#    #+#             */
/*   Updated: 2021/06/18 15:36:13 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, int n)
{
	char	*found;
	int		count;
	int		count2;

	count = 0;
	found = 0;
	if (ft_strlen(str2) == 0)
		return ((char *)str1);
	while (count < n && str1[count] != '\0')
	{
		if (str1[count] == str2[0])
		{
			count2 = 0;
			while (count + count2 < n && str1[count + count2] == str2[count2])
			{
				count2++;
				if (str2[count2] == '\0')
					return ((char *)&str1[count]);
			}
		}
		count++;
	}
	return (0);
}
