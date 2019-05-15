#include "../../MainHeader/ft_printf.h"

void	ft_put_space_integer(t_pf *data)
{
	int		i;

	if (CHECK_BIT(data->flags, 4) || !CHECK_BIT(data->flags, 3)
		|| g_buffer->str[0] == '+' || g_buffer->str[0] == '-')
		return ;
	check_and_add(g_buffer->str_len);
	g_buffer->final[0] = ' ';
	i = 0;
	while (g_buffer->str[++i - 1] != '\0' && g_buffer->str[i - 1])
		g_buffer->final[i] = g_buffer->str[i - 1];
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size + 1);
	g_buffer->str_len = i;
}
