/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 12:26:00 by sselusa           #+#    #+#             */
/*   Updated: 2019/10/22 21:49:02 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_structs.h"
#include <stdio.h>
#include <limits.h>

static char			*combine_ld(unsigned long fract,
						unsigned long whole, int sign, int precision)
{
	char				*str;
	char				*str_tmp_f;
	char				*str_tmp_w;
	size_t				len;

	str_tmp_f = ft_ulltoa(fract);
	str_tmp_w = ft_ulltoa(whole);
	len = ft_strlen(str_tmp_f) + ft_strlen(str_tmp_w) + (sign == -1 ? 1 : 0);
	str = ft_strnew(len + 1);
	if (sign == -1)
		str[0] = '-';
	str = ft_strcat(str, str_tmp_w);
	if (precision != 0)
	{
		str = ft_strcat(str, ".");
		str = ft_strncat(str, str_tmp_f, precision);
	}
	free(str_tmp_f);
	free(str_tmp_w);
	return (str);
}

static void			get_a(t_ld *ld, int sign,
							long double num, int precision)
{
	unsigned long			whole;
	unsigned long			fract;
	unsigned long			last;
	unsigned long			last_two;

	whole = (unsigned long)num;
	last_two = (unsigned long)(ft_power(10, (precision + 2)) * (num - whole));
	last = (unsigned long)(ft_power(10, (precision + 1)) * (num - whole));
	fract = (unsigned long)(ft_power(10, (precision)) * (num - whole));
	if (last - (fract * 10) > 5)
		fract++;
	else if (last - (fract * 10) == 5 && last_two - (last * 10) > 0)
		fract++;
	else if (last - (fract * 10) == 5 && last_two - (last * 10) == 0)
		fract += is_even(fract) ? 0 : 1;
	else
		ld->str = NULL;
	ld->str = combine_ld(fract, whole, sign, precision);
}

static t_ld			parse_ld(long double num, int precision)
{
	__int128_t			mask;
	int					sign;
	t_ld				ld;

	num = (double)num;
	ld.str = NULL;
	ld.ld.ld_tmp = num;
	mask = (__int128_t)0x7FFF << 64;
	ld.exp = (int)((ld.ld.int_tmp & mask) >> 64);
	mask = (__int128_t)1 << 73;
	ld.negative = (int)((ld.ld.int_tmp & mask) >> 73);
	if (check_fields(&ld))
		return (ld);
	sign = 1;
	if (num < 0)
	{
		sign = -1;
		num *= -1;
	}
	get_a(&ld, sign, num, precision);
	return (ld);
}

static char			*ftoa(long double num, int precision)
{
	t_ld				ld;

	if (precision == NO_FLAG)
		precision = 6;
	ld = parse_ld(num, precision);
	return (ld.str);
}

void				add_double(char *part, t_format format)
{
	char	*arg;

	format.flags.zero =
			format.prec != NO_FLAG ? 0 : format.flags.zero;
	arg = (ftoa(format.type == LDOUBLE ? va_arg(g_pf.args, long double)
			: va_arg(g_pf.args, double), format.prec));
	format.prec = format.prec == NO_FLAG ? 0 : format.prec;
	ft_isdigit(arg[0]) && format.flags.plus ? format.width -= 1 : format.width;
	fill_float_format(format, arg);
	free(arg);
	ft_lstaddback(&g_pf.buf, &part[format.i],
			ft_strlen(&part[format.i]) + 1);
	free(part);
}
