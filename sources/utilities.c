#include "../ft_printf.h"

void	ft_truesubtract(int *num, int val)
{
	if (*num < 0)
		*num += val;
	else if (*num > 0)
		*num -= val;
}
