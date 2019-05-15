#include "../../MainHeader/ft_printf.h"

void	ft_put_precision_unsigned(t_pf *data)
{
	int		i;
	int		j;
	int		len;

	if (!data->precision)
		return ;
	if (g_buffer->str[0] == '0' && data->precision == -1)
	{
		g_buffer->str[0] = '\0';
		g_buffer->str_len = 0;
		return ;
	}
	len = num_len_unsigned(g_unsigned_integer) - data->precision;
	if (len >= 0)
		return ;
	check_and_add(len * (-1));
	i = 0;
	j = 0;
	while (j++ < (-1) * len)
		g_buffer->final[i++] = '0';
	j = 0;
	while (g_buffer->str[j] != '\0' && g_buffer->str[j])
		g_buffer->final[i++] = g_buffer->str[j++];
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, i);
}
