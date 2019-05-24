/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_part.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:20:36 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/23 15:47:30 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			fill_float_format(t_format format, char *arg)
{
	int			len;
	int			differ;

	if (!arg)
		return ;
	len = ft_strlen(arg);
	differ = format.width > len ? format.width - len : 0;
	if (format.flags.minus)
	{
		if (format.flags.plus)
			ft_isdigit(arg[0]) ? ft_lstaddback(&g_pf.buf, "+", 2) : 0;
		ft_lstaddback(&g_pf.buf, arg, len + 1);
	}
	if (format.width != NO_VALUE && format.width != NO_FLAG)
		fill_differ(differ, format);
	if (!format.flags.minus)
	{
		if (format.flags.plus)
			ft_isdigit(arg[0]) ? ft_lstaddback(&g_pf.buf, "+", 2) : 0;
		ft_lstaddback(&g_pf.buf, arg, len + 1);
	}
}

void			fill_int_format(t_format format, char *arg)
{
	int			len;
	int			differ;
	char		*temp;
	char		*prefix;

	if (format.type != OCTAL && format.type != B_HEX
			&& format.type != S_HEX && format.type != PTR)
		prefix = get_prefix(arg, &format);
	else
		prefix = get_base_prefix(arg, &format);
	len = ft_strlen(arg);
	temp = add_precision_zeros(format, &len, arg);
	differ = format.width > len ? format.width - len : 0;
	add_prefix(format, differ, prefix, len);
	ft_lstaddback(&g_pf.buf, temp, len + 1);
	if (format.flags.minus)
		fill_differ(differ, format);
	free(temp);
	free(prefix);
}

void			fill_text_format(t_format format, char *arg)
{
	int			len;
	int			differ;

	len = arg ? ft_strlen(arg) : 6;
	if (arg && !arg[0] && (format.type == CHAR))
		len = 1;
	if (format.type == STRING && format.prec != NO_FLAG && arg)
	{
		format.prec = format.prec == NO_VALUE ? 0 : format.prec;
		len = format.prec < len ? format.prec : len;
	}
	differ = format.width > len ? format.width - len : 0;
	if (arg && !arg[0])
		arg = ft_strdup("\0");
	else
		arg = arg ? ft_strsub(arg, 0, len) : ft_strdup("(null)");
	if (format.flags.minus && arg)
		ft_lstaddback(&g_pf.buf, arg, len + 1);
	fill_differ(differ, format);
	if (!format.flags.minus && arg)
		ft_lstaddback(&g_pf.buf, arg, len + 1);
	free(arg);
}

void			fill_format(t_format format, char *arg)
{
	int			len;
	int			differ;
	char		*temp;

	if (!arg)
		return ;
	len = ft_strlen(arg);
	if (format.prec != NO_FLAG)
	{
		temp = ft_strnew(len < format.prec ? format.prec : len);
		ft_memcpy(&temp[len < format.prec ? format.prec - len : 0], arg, len);
		ft_memset(temp, '0', len < format.prec ? format.prec - len : 0);
		len = format.prec > len ? format.prec : len;
	}
	else
		temp = ft_strdup(arg);
	differ = format.width > len ? format.width - len : 0;
	if (format.flags.minus)
		ft_lstaddback(&g_pf.buf, temp, len + 1);
	fill_differ(differ, format);
	if (!format.flags.minus)
		ft_lstaddback(&g_pf.buf, temp, len + 1);
	free(temp);
}
