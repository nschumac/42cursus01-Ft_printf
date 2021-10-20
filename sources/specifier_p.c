#include "ft_printf.h"

void	ft_fixwidthprecision_p(unsigned long long num, char *strnum, int len)
{
	if (g_precision_status == PRECISE && g_precision >= 0)
	{
		if (g_precision == 0 && num == 0)
		{
			len--;
			strnum[0] = '\0';
		}
	}
	if (ft_abs(g_width) < len)
		g_width = 0;
	else
		ft_truesubtract(&g_width, len);
}

void	ft_print_p(void)
{
	unsigned long long	num;
	char				*strnum;

	num = va_arg(g_ap, unsigned long long);
	if (g_flag == ZERO)
		ft_putstr_fd("0x", FD);
	strnum = ft_itoabase(num, "0123456789abcdef");
	ft_fixwidthprecision_p(num, strnum, ft_strlen(strnum) + 2);
	if (g_width > 0 && g_flag != MINUS)
		ft_padding();
	if (g_flag != ZERO)
		ft_putstr_fd("0x", FD);
	ft_putstr_fd(strnum, FD);
	if (g_width)
		ft_padding();
	g_charcount += 2 + ft_strlen(strnum);
}
