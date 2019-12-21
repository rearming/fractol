/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 04:21:34 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/22 21:49:02 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	g_pf;

char		*get_buffer(t_list **list, size_t total_len)
{
	char		*buffer;
	int			start;
	t_list		*temp;

	start = 0;
	if (!(buffer = (char*)malloc(sizeof(char) * (total_len + 1))))
		raise_error(ERR_MALLOC);
	while (*list)
	{
		ft_memcpy(&buffer[start], (*list)->content, (*list)->content_size - 1);
		start += (*list)->content_size - 1;
		temp = (*list);
		(*list) = (*list)->next;
		free(temp->content);
		free(temp);
	}
	buffer[total_len] = '\0';
	return (buffer);
}

char		*get_result_string(t_list **list, int *out_symbols_count)
{
	t_list		*tmp_count;

	if (!list)
		raise_error(ERR_NULL_LIST);
	tmp_count = *list;
	*out_symbols_count = 0;
	while (tmp_count)
	{
		*out_symbols_count += tmp_count->content_size - 1;
		tmp_count = tmp_count->next;
	}
	return (get_buffer(&g_pf.buf, *out_symbols_count));
}

t_format	get_format(char *part)
{
	t_format	format;

	format.flags = (t_flags){0, 0, 0, 0, 0};
	format = (t_format){format.flags, 0, 0, 0, 0, 0};
	if (part[format.i] != '%')
		return ((t_format)
				{format.flags, 0, 0, BREAK, BREAK, 0});
	else
		format.i++;
	format.flags = get_flags(part, &format.i);
	format.width = get_width(part, &format.i);
	if (format.width < 0 && format.width != NO_FLAG && format.width != NO_VALUE)
	{
		format.width *= -1;
		format.flags.minus = 1;
	}
	format.prec = get_precision(part, &format.i);
	if ((format.type_flag = get_type_flag(part, &format.i)) == BREAK)
		return (format);
	if (format.type_flag != NO_FLAG
		&& part[format.i] != 'U' && part[format.i] != 'O')
		format.i++;
	if ((format.type = get_type(part, format.i)) != BREAK)
		format.i++;
	return (format);
}

void		add_buf_node(char *part)
{
	t_format	format;

	format = get_format(part);
	if (format.type_flag == BREAK || format.type == BREAK)
		add_text(part, format);
	if (format.type == CHAR)
		add_char(part, format);
	if (format.type == STRING)
		add_string(part, format);
	if (format.type == PERCENT)
		add_percent(part, format);
	if (format.type == INT)
		add_signed(part, format);
	if (format.type == UNSIGNED)
		add_unsigned(part, format);
	if (format.type == DOUBLE)
		add_double(part, format);
	if (format.type == B_HEX || format.type == S_HEX
		|| format.type == PTR || format.type == OCTAL
			|| format.type == BINARY)
		add_base(part, format);
}

char		*get_formatted_string(int *out_symbols_count, const char *format)
{
	int			i;
	char		**parts;

	parts = split_flags(format, '%');
	i = 0;
	while (parts[i])
	{
		add_buf_node(parts[i]);
		i++;
	}
	free(parts);
	return (get_result_string(&g_pf.buf, out_symbols_count));
}
