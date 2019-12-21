/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:06:56 by sleonard          #+#    #+#             */
/*   Updated: 2019/08/01 11:04:43 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long		ft_atoull(const char *str)
{
	unsigned long long	num;
	size_t				pos;

	if (!str)
		return (0);
	num = 0;
	pos = pass_spaces(str);
	while (ft_isdigit(str[pos]))
	{
		num = num * 10 + str[pos] - '0';
		pos++;
	}
	return ((num));
}
