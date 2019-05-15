#include "../../MainHeader/ft_printf.h"

int		num_len(long long int num)
{
	int			i;
	__int128_t	n;

	n = num;
	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}
