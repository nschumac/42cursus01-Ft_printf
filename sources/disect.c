#include "../ft_printf.h"

void	ft_offsetflags(void)
{
	while (*g_str == '0' || *g_str == ' ' || *g_str == '#')
		g_str++;
}

void	ft_setflags(void)
{
	g_flag = NONE;
	if (*g_str == '-')
		g_flag = MINUS;
	else if (*g_str == '0')
		g_flag = ZERO;
	else if (*g_str == '+')
		g_flag = PLUS;
	else if (*g_str == ' ')
		g_flag = SPACE;
	else if (*g_str == '#')
		g_flag = HASHTAG;
	if (g_flag != NONE)
		ft_offsetflags();
}

void	ft_setwidth(void)
{
	if (*g_str == '-' || *g_str == '+')
	{
		while (*g_str == '-' || *g_str == '+')
			g_str++;
		if (*g_str != '*')
			g_str--;
	}
	if (*g_str == '*')
	{
		g_str++;
		g_width = va_arg(g_ap, int);
	}
	else
	{
		g_width = ft_atoi((const char *)g_str);
		while ((*g_str >= '0' && *g_str <= '9')
			|| *g_str == '-' || *g_str == '+')
			g_str++;
	}
}

void	ft_setprecision(void)
{
	g_precision_status = NONE;
	if (*g_str == '.')
	{
		g_precision = 0;
		g_str++;
		if (*g_str == '-' || *g_str == '+')
		{
			while (*g_str == '-' || *g_str == '+')
				g_str++;
			if (*g_str != '*')
				g_str--;
		}
		if (*g_str == '*')
			g_precision = va_arg(g_ap, int);
		else
			g_precision = ft_atoi((const char *)g_str);
		while ((*g_str >= '0' && *g_str <= '9')
			|| *g_str == '-' || *g_str == '+' || *g_str == '*')
			g_str++;
		g_precision_status = PRECISE;
	}
}

void	ft_disect(void)
{
	g_str++;
	ft_setflags();
	ft_setwidth();
	ft_setprecision();
}
