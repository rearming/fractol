/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:34:41 by sselusa           #+#    #+#             */
/*   Updated: 2019/05/23 17:21:23 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static void				check_exp_zero(t_ld *ld)
{
	__int128_t			mask;

	mask = (__int128_t)1 << 63;
	if (((int)(ld->ld.int_tmp & mask)) == 0)
	{
		mask = (__int128_t)0x7FFFFFFFFFFFFFFF;
		if (((int)(ld->ld.int_tmp & mask)) == 0)
		{
			if (ld->negative == 1)
				ld->str = ft_strdup("-0.0");
			else
				ld->str = ft_strdup("0.0");
		}
		else
			ld->exp = -16382;
	}
	else
		ld->exp = -16382;
}

static void				infinity(t_ld *ld)
{
	__int128_t			mask;

	mask = (__int128_t)0xFFFFFFFFFFFFFFF;
	if (((int)(ld->ld.int_tmp & mask)) == 0)
		if (ld->negative == 1)
			ld->str = ft_strdup("-Inf");
		else
			ld->str = ft_strdup("Inf");
	else
		ld->str = ft_strdup("NaN");
}

static void				check_exp_max(t_ld *ld)
{
	__int128_t			mask;

	mask = (__int128_t)3 << 62;
	if ((int)(((ld->ld.int_tmp & mask)) >> 62) == 0)
		infinity(ld);
	else if ((int)(((ld->ld.int_tmp & mask)) >> 62) == 1)
		ld->str = ft_strdup("NaN");
	else if ((int)(((ld->ld.int_tmp & mask)) >> 62) == 2)
		infinity(ld);
	else if ((int)(((ld->ld.int_tmp & mask)) >> 62) == 3)
		ld->str = ft_strdup("NaN");
}

char					*check_fields(t_ld *ld)
{
	if (ld->exp == 0)
		check_exp_zero(ld);
	else if (ld->exp == 32767)
		check_exp_max(ld);
	else
		ld->exp -= 16383;
	return (ld->str);
}
