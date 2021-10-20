#include "../ft_printf.h"

char	*ft_fixprecision_xX(unsigned long num, const char *set)
{
	char	*ret;
	int		retlen;

	ret = ft_itoabase(num, set);
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
		if (g_precision > 0)
			ft_truesubtract(&g_width, g_precision);
	}
	g_charcount += ft_strlen(ret);
	return (ret);
}

void	ft_fixwidth_xX(int retlen, int neg)
{
	if (ft_abs(g_width) > retlen)
		ft_truesubtract(&g_width, retlen + neg);
	else
		g_width = 0;
	if (g_width < 0)
		g_flag = NONE;
}

void	ft_print_xX(const char *set)
{
	char			*str;
	unsigned long	num;

	num = va_arg(g_ap, unsigned int);
	str = ft_fixprecision_xX(num, set);
	ft_fixwidth_xX(ft_strlen(str), (num < 0));
	if (g_flag == ZERO)
		ft_padding();
	else if (g_flag == NONE && g_width > 0)
		ft_padding();
	if (g_precision_status == PRECISE && g_precision > 0)
		ft_writepadding(g_precision, '0');
	ft_putstr_fd(str, FD);
	ft_padding();
	free(str);
}
