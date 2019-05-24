/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:43:00 by sselusa           #+#    #+#             */
/*   Updated: 2019/05/22 11:56:22 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa(int n)
{
	unsigned int		num;
	int					qt;
	char				*res;
	int					sign;

	sign = n < 0 ? 1 : 0;
	num = n;
	num = num * (sign ? -1 : 1);
	qt = 1 + sign;
	while (n / 10)
	{
		n = n / 10;
		qt++;
	}
	if (!(res = ft_strnew(qt)))
		return (NULL);
	if (sign)
		res[0] = '-';
	while (qt-- >= 1 + sign)
	{
		res[qt] = num % 10 + '0';
		num = num / 10;
	}
	return (res);
}
