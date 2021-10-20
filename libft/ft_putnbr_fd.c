/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:50:40 by nschumac          #+#    #+#             */
/*   Updated: 2021/06/21 13:15:11 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long		num;
	char		buf[10];
	int			count;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	count = 9;
	while (num > 0)
	{
		buf[count] = num % 10 + '0';
		num /= 10;
		count--;
	}
	while (count < 9)
	{
		count++;
		write(fd, &buf[count], 1);
	}
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	long		num;
	char		buf[10];
	int			count;

	num = n;
	count = 9;
	while (num > 0)
	{
		buf[count] = num % 10 + '0';
		num /= 10;
		count--;
	}
	while (count < 9)
	{
		count++;
		write(fd, &buf[count], 1);
	}
}

void	ft_putnbrbase_fd(unsigned long long n, int fd, const char *set)
{
	unsigned long long	set_size;
	unsigned long long	pow;

	pow = 1;
	set_size = ft_strlen(set);
	while (n / pow >= set_size)
		pow *= set_size;
	while (pow > 0)
	{
		write(fd, (char *)&set[(n / pow) % set_size], 1);
		pow /= set_size;
	}
}
