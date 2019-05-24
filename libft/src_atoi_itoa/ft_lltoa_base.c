/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rearming <rearming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 19:22:51 by rearming          #+#    #+#             */
/*   Updated: 2019/05/22 11:56:40 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*alloc_formatted(long long nbr,
					int base, char capital, char format)
{
	int		size;
	char	*res;

	format = base > 10 || base == 8 ? format : 0;
	size = nbr < 0 ? 1 : 0;
	if (base != 8)
		size += format ? 2 : 0;
	else
		size += format ? 1 : 0;
	while (nbr >= base || nbr <= -base)
	{
		nbr /= base;
		size++;
	}
	size++;
	res = ft_strnew(size);
	ft_memset(res, '*', size);
	res[0] = nbr < 0 ? '-' : '+';
	if (format)
	{
		res[res[0] == '-' ? 1 : 0] = '0';
		if (base != 8)
			res[res[0] == '0' ? 1 : 2] = capital ? 'X' : 'x';
	}
	return (res);
}

char			*ft_lltoa_base(long long nbr,
					int base, char capital, char format)
{
	char		*res;
	size_t		len;
	char		c;
	size_t		limit;

	c = capital ? 'A' : 'a';
	limit = nbr < 0 ? 1 : 0;
	if (base > 10)
		limit += format ? 2 : 0;
	if (base == 8)
		limit += format ? 1 : 0;
	res = alloc_formatted(nbr, base, capital, format);
	nbr *= nbr < 0 ? -1 : 1;
	len = ft_strlen(res);
	while (len-- > limit)
	{
		res[len] = (nbr % base) + (nbr % base > 9 ? c - 10 : '0');
		nbr /= base;
	}
	return (res);
}
