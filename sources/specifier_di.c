#include "../ft_printf.h"

char	*ft_fixprecision_di(long num)
{
	char	*ret;
	int		retlen;

	ret = ft_itoa(ft_abs(num));
	retlen = ft_strlen(ret);
	if (g_precision_status == PRECISE && g_precision >= 0)
	{
		if (!ft_strncmp(ret, "0", 1) && g_precision == 0)
			ret[0] = '\0';
		g_precision -= retlen;
		if (g_flag == ZERO)
			g_flag = NONE;
		if (g_precision > ft_abs(g_width))
			g_width = 0;
		else if (g_precision > 0)
			ft_truesubtract(&g_width, g_precision);
	}
	return (ret);
}

void	ft_fixwidth_di(int retlen, int neg)
{
	if (g_width < 0)
		g_flag = NONE;
	if (ft_abs(g_width) > retlen)
		ft_truesubtract(&g_width, retlen + neg);
	else
		g_width = 0;
	if (retlen == 11)
		neg = 0;
	g_charcount += retlen + neg;
}

void	ft_print_di(void)
{
	char	*str;
	long	num;

	num = va_arg(g_ap, int);
	str = ft_fixprecision_di(num);
	ft_fixwidth_di(ft_strlen(str), (num < 0));
	if (g_flag == ZERO)
	{
		if (num < 0 && num != -2147483648)
			ft_putchar_fd('-', FD);
		ft_padding();
		num = ft_abs(num);
	}
	else if (g_flag == NONE && g_width > 0)
		ft_padding();
	if (num < 0 && num != -2147483648)
		ft_putchar_fd('-', FD);
	if (g_precision_status == PRECISE && g_precision > 0)
		ft_writepadding(g_precision, '0');
	ft_putstr_fd(str, FD);
	ft_padding();
	free(str);
}
