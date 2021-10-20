/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:02:46 by nschumac          #+#    #+#             */
/*   Updated: 2021/06/25 17:22:55 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_abs(int num)
{
	long	buf;

	buf = (long)num;
	if (buf < 0)
		buf *= -1;
	return (buf);
}

char	*ft_handlezero(void)
{
	char	*ret;

	ret = (char *)malloc(2);
	if (!ret)
		return (0);
	ret[0] = '0';
	ret[1] = '\0';
	return (ret);
}

char	*ft_itoa(int n)
{
	int		length;
	long	num;
	char	*yeet;

	if (n == 0)
		return (ft_handlezero());
	length = 1;
	num = n / 10;
	while (num != 0 && length++)
		num /= 10;
	if (n < 0)
		length++;
	yeet = (char *)malloc(length + 1);
	if (!yeet)
		return (0);
	if (n < 0)
		yeet[0] = '-';
	yeet[length] = '\0';
	while (n != 0)
	{
		yeet[--length] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (yeet);
}

char	*ft_itoabase(unsigned long long num, const char *set)
{
	unsigned long long	set_size;
	unsigned long long	pow;
	char				*ret;
	int					len;
	int					count;

	pow = 1;
	len = 0;
	count = 0;
	set_size = ft_strlen(set);
	while (++len && num / pow >= set_size)
		pow *= set_size;
	ret = (char *)malloc(len + 1);
	while (pow > 0)
	{
		ret[count] = set[(num / pow) % set_size];
		pow /= set_size;
		count++;
	}
	ret[count] = '\0';
	return (ret);
}
