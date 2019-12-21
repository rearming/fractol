/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rearming <rearming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 20:28:25 by rearming          #+#    #+#             */
/*   Updated: 2019/08/01 11:04:43 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "stdio.h"

static int	count_fract_digits(const char *fract_part)
{
	int		i;

	i = 0;
	while (ft_isdigit(fract_part[i]))
		i++;
	return (i);
}

double		get_fract_part(long long fract, const char *fract_part)
{
	const int	digits = count_fract_digits(fract_part);
	int			i;
	double		fract_res;

	i = 0;
	fract_res = (double)fract;
	while (i < digits)
	{
		fract_res /= 10;
		i++;
	}
	return (fract_res);
}

double		ft_strtod(const char *str)
{
	double		result;
	long long	whole;
	long long	fract;
	size_t		begin;
	int			is_negative;

	fract = 0;
	begin = pass_spaces(str);
	whole = ft_atoll(&str[begin]);
	whole = whole < 0 ? -whole : whole;
	is_negative = str[begin] == '-' ? -1 : 1;
	begin += str[begin] == '-';
	if (str[begin + ft_count_digits(whole)] == '.')
		fract = ft_atoll(&str[begin + ft_count_digits(whole) + 1]);
	result = ((double)whole + get_fract_part(fract,
			&str[begin + ft_count_digits(whole) + 1]));
	if (begin > 0 && str[begin - 1] != '-' && result < 0)
		return (-1.0);
	return (result * is_negative);
}
