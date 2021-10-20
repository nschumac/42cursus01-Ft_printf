#include "../ft_printf.h"

void	ft_print_c(char c)
{
	ft_truesubtract(&g_width, 1);
	if (g_width > 0 && g_flag != MINUS)
		ft_padding();
	ft_putchar_fd(c, FD);
	g_charcount++;
	if (g_width)
	{
		g_flag = NONE;
		ft_padding();
	}
}
