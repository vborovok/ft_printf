#include "../../MainHeader/ft_printf.h"

int			fill_str(t_pf *data, int i)
{
	while (data->indents > 0)
	{
		g_buffer->final[i] = data->indents_symb;
		i++;
		data->indents--;
	}
	return (i);
}

int			cp_str(int i)
{
	int j;

	j = 0;
	while (g_buffer->str[j] != '\0')
		g_buffer->final[i++] = g_buffer->str[j++];
	return (i);
}

void		set_indents_str(t_pf *data)
{
	int		i;
	int		len;

	len = data->indents - g_buffer->str_len;
	i = 0;
	if (data->indents < len || len < 0)
		return ;
	data->indents = len;
	if (CHECK_BIT(data->flags, 5))
	{
		i = cp_str(i);
		i = fill_str(data, i);
	}
	else
	{
		i = fill_str(data, i);
		i = cp_str(i);
	}
	g_buffer->final[i++] = '\0';
	g_buffer->str_len = i - 1;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size + 1);
}

void		set_precision_str(t_pf *data)
{
	int		i;


	i = 0;
	while (data->precision > 0 && g_buffer->str[i] != '\0')
	{
		g_buffer->final[i] = g_buffer->str[i];
		i++;
		data->precision--;
	}
	g_buffer->final[i] = '\0';
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size + 1);
}

void		string_process(t_pf *data, va_list args)
{
	char	*buf;

	buf = va_arg(args, char*);
	if (buf != NULL)
	{
		ft_strcpy(g_buffer->str, buf);
		g_buffer->str_len = ft_strlen(g_buffer->str);
	}
	else
	{
		ft_strcpy(g_buffer->str, "(null)");
		g_buffer->str_len = 6;
	}
	if (data->precision != 0)
		set_precision_str(data);
	if (data->indents != 0)
		set_indents_str(data);
}
