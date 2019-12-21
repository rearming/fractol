/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:20:52 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/22 21:49:02 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	g_pf;

void		add_text(char *part, t_format format)
{
	ft_lstaddback(&g_pf.buf, &part[format.i],
			ft_strlen(&part[format.i]) + 1);
	free(part);
}

void		add_string(char *part, t_format format)
{
	if (format.type == STRING)
		fill_text_format(format, va_arg(g_pf.args, char*));
	ft_lstaddback(&g_pf.buf, &part[format.i],
			ft_strlen(&part[format.i]) + 1);
	free(part);
}

void		add_char(char *part, t_format format)
{
	char	*res;
	int		arg;

	res = ft_strnew(4);
	arg = va_arg(g_pf.args, int);
	if (format.type == CHAR)
		res[0] = (char)arg;
	else if (format.type == WCHAR)
	{
		res[0] = ((arg >> 24) & 0xFF);
		res[1] = ((arg >> 16) & 0xFF);
		res[2] = ((arg >> 8) & 0xFF);
		res[3] = arg & 0xFF;
	}
	format.prec = 1;
	fill_text_format(format, res);
	free(res);
	ft_lstaddback(&g_pf.buf, &part[format.i],
			ft_strlen(&part[format.i]) + 1);
	free(part);
}

void		add_percent(char *part, t_format format)
{
	char	*res;

	res = ft_strnew(1);
	format.type = CHAR;
	res[0] = '%';
	format.prec = 1;
	fill_text_format(format, res);
	free(res);
	ft_lstaddback(&g_pf.buf, &part[format.i],
				ft_strlen(&part[format.i]) + 1);
	free(part);
}
