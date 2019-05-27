/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:54:24 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/13 11:19:47 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_digits(int nb)
{
	int		symb_n;

	symb_n = 0;
	while ((nb >= 10) || (nb <= -10))
	{
		symb_n++;
		nb /= 10;
	}
	return (symb_n + 1);
}