#include "ft_printf.h"

void	ft_writepadding(int amount, char type)
{
	int	count;

	count = 0;
	while (++count && count <= amount)
		write(FD, &type, 1);
	g_charcount += amount;
}

void	ft_padding(void)
{
	if (g_flag == ZERO)
		ft_writepadding(ft_abs(g_width), '0');
	else if (g_flag == MINUS || g_flag == NONE)
		ft_writepadding(ft_abs(g_width), ' ');
	else if (g_flag == SPACE)
		ft_writepadding(1, ' ');
	g_width = 0;
}
