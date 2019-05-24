/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whole_nbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:35:47 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/23 16:50:00 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*convert_signed_arg(t_format format)
{
	if (format.type_flag == NO_FLAG)
		return (ft_lltoa(va_arg(g_pf.ap, int)));
	if (format.type_flag == CHAR)
		return (ft_lltoa((char)va_arg(g_pf.ap, int)));
	if (format.type_flag == INT_MAX)
		return (ft_lltoa(va_arg(g_pf.ap, intmax_t)));
	if (format.type_flag == SHORT)
		return (ft_lltoa((short)va_arg(g_pf.ap, int)));
	if (format.type_flag == LONG)
		return (ft_lltoa(va_arg(g_pf.ap, long)));
	if (format.type_flag == LONG_LONG || format.type_flag == LDOUBLE)
		return (ft_lltoa(va_arg(g_pf.ap, long long)));
	return (NULL);
}

char		*convert_unsigned_arg(t_format format)
{
	if (format.type == PTR)
		return (ft_ulltoa(va_arg(g_pf.ap, unsigned long long)));
	if (format.type_flag == NO_FLAG)
		return (ft_ulltoa(va_arg(g_pf.ap, unsigned)));
	if (format.type_flag == INT_MAX)
		return (ft_ulltoa(va_arg(g_pf.ap, intmax_t)));
	if (format.type_flag == LONG)
		return (ft_ulltoa(va_arg(g_pf.ap, unsigned long)));
	if (format.type_flag == CHAR)
		return (ft_ulltoa((unsigned char)va_arg(g_pf.ap, unsigned)));
	if (format.type_flag == SHORT)
		return (ft_ulltoa((unsigned short)va_arg(g_pf.ap, unsigned)));
	if (format.type_flag == LONG_LONG || format.type_flag == LDOUBLE)
		return (ft_ulltoa(va_arg(g_pf.ap, unsigned long long)));
	return (NULL);
}

void		add_signed(char *part, t_format format)
{
	char	*arg;

	format.flags.zero =
			format.prec != NO_FLAG ? 0 : format.flags.zero;
	format.prec = format.prec == NO_VALUE ? 1 : format.prec;
	arg = convert_signed_arg(format);
	if (!ft_atoi(arg) && format.prec != NO_FLAG && format.prec == 0)
		arg[0] = 0;
	ft_isdigit(arg[0]) && format.flags.plus ? format.width -= 1 : format.width;
	fill_int_format(format, arg);
	free(arg);
	ft_lstaddback(&g_pf.buf, &part[format.i],
			ft_strlen(&part[format.i]) + 1);
	free(part);
}

void		add_unsigned(char *part, t_format format)
{
	char	*arg;

	arg = convert_unsigned_arg(format);
	if (!ft_atoi(arg) && format.prec != NO_FLAG)
		arg[0] = 0;
	fill_format(format, arg);
	free(arg);
	ft_lstaddback(&g_pf.buf, &part[format.i],
			ft_strlen(&part[format.i]) + 1);
	free(part);
}

void		add_base(char *part, t_format format)
{
	char	*arg;
	char	*temp;

	format.flags.zero =
			format.prec != NO_FLAG ? 0 : format.flags.zero;
	format.flags.plus = 0;
	arg = convert_unsigned_arg(format);
	temp = arg;
	if (format.type == B_HEX || format.type == S_HEX || format.type == PTR)
		arg = ft_ulltoa_base(ft_atoull(arg), 16,
				format.type == B_HEX ? 1 : 0, 0);
	else
		arg = ft_ulltoa_base(ft_atoull(arg),
				format.type == BINARY ? 2 : 8, 0, 0);
	if ((!ft_atoll_base(arg, 16)) && format.prec != NO_FLAG
		&& (format.type != OCTAL || !format.flags.grid) && format.type != PTR)
		arg[0] = 0;
	arg[0] = format.type == PTR
			&& (!format.prec || format.prec == NO_VALUE) ? 0 : arg[0];
	fill_int_format(format, arg);
	free(arg);
	free(temp);
	ft_lstaddback(&g_pf.buf, &part[format.i],
			ft_strlen(&part[format.i]) + 1);
	free(part);
}
