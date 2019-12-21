/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:33:02 by sselusa           #+#    #+#             */
/*   Updated: 2019/08/01 11:04:43 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			get_sign(const char *str, size_t *pos)
{
	int		sign;

	sign = 1;
	if (str[*pos] == '-' || str[*pos] == '+')
	{
		if (str[*pos] == '-')
			sign = -1;
		(*pos)++;
	}
	return (sign);
}

int					ft_atoi(const char *str)
{
	unsigned long		num;
	int					sign;
	size_t				pos;

	num = 0;
	pos = pass_spaces(str);
	sign = get_sign(str, &pos);
	while (ft_isdigit(str[pos]))
	{
		if (sign == 1 && (num > OVERFLOW_FT ||
			(num == OVERFLOW_FT && str[pos] - '0' > 7)))
			return (-1);
		if (sign == -1 && (num > OVERFLOW_FT ||
			(num == OVERFLOW_FT && str[pos] - '0' > 8)))
			return (0);
		num = num * 10 + str[pos] - '0';
		pos++;
	}
	return ((int)(sign * num));
}
