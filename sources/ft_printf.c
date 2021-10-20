#include "ft_printf.h"

void	ft_dotype(void)
{
	if (*g_str == '%')
		ft_print_c('%');
	else if (*g_str == 'c')
		ft_print_c(va_arg(g_ap, int));
	else if (*g_str == 's')
		ft_print_s();
	else if (*g_str == 'p')
		ft_print_p();
	else if (*g_str == 'd' || *g_str == 'i')
		ft_print_di();
	else if (*g_str == 'u')
		ft_print_xX("0123456789");
	else if (*g_str == 'x')
		ft_print_xX("0123456789abcdef");
	else if (*g_str == 'X')
		ft_print_xX("0123456789ABCDEF");
	g_str++;
}

int	ft_printf(const char *str, ...)
{
	g_str = (char *)str;
	g_charcount = 0;
	va_start(g_ap, str);
	while (*g_str != '\0')
	{
		if (*g_str == '%')
		{
			ft_disect();
			ft_dotype();
		}
		else
		{
			g_charcount++;
			write(1, g_str, 1);
			g_str++;
		}
	}
	va_end(g_ap);
	return (g_charcount);
}
