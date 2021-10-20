#include "../ft_printf.h"

void	ft_fixwidthprecision_s(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (g_precision < len && g_precision_status == PRECISE && g_precision >= 0)
	{
		len = g_precision;
		*(str + len) = '\0';
	}
	if (ft_llabs(g_width) < len)
		g_width = 0;
	else
		ft_truesubtract(&g_width, len);
	g_charcount += len;
}

void	ft_print_s(void)
{
	char	*str;

	str = va_arg(g_ap, char *);
	if (!str)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	ft_fixwidthprecision_s(str);
	if (g_width > 0 && g_flag != MINUS)
		ft_padding();
	ft_putstr_fd(str, FD);
	if (g_width)
		ft_padding();
	free(str);
}
