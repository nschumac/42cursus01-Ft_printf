#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** INCLUDES
*/
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "42cursus00-Libft/libft.h"
/*
** INCLUDES
*/

/*
** MACROS
*/
# define TRUE 1
# define FALSE 0
# define FD 1
/*
** MACROS
*/

/*
** STRUCTS, ENUMS, UNIONS, TYPEDEFS
*/
typedef enum e_length
{
	NONE = -1,
	H = 0,
	HH,
	L,
	LL,
	PRECISE
}				t_length;

typedef enum e_flags
{
	MINUS = 0,
	ZERO,
	HASHTAG,
	SPACE,
	PLUS
}				t_flags;

/*
** STRUCTS, ENUMS, UNIONS
*/

/*
** GLOBALS
*/
va_list	g_ap;
char	*g_str;
int		g_length;
int		g_width;
int		g_precision;
char	g_precision_status;
int		g_flag;
int		g_charcount;
/*
** GLOBALS
*/

/*
** PROTOTYPES
*/
int		ft_printf(const char *str, ...);
void	ft_padding(void);
void	ft_disect(void);
void	ft_print_c(char c);
void	ft_print_s(void);
void	ft_print_p(void);
void	ft_writepadding(int amount, char type);
int		ft_numlen(unsigned long long num);
void	ft_print_di(void);
void	ft_truesubtract(int *num, int val);
void	ft_print_xX(const char *set);
/*
** PROTOTYPES
*/
#endif
