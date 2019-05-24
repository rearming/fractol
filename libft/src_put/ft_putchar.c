/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:22:12 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/13 11:19:47 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

static void		print_utf(char c)
{
	unsigned char	uchar;
	unsigned char	oct1;
	unsigned char	oct2;

	uchar = (129 + c) + 127;
	oct1 = uchar >> 6;
	oct1 = oct1 | 192;
	uchar = uchar << 2;
	uchar = uchar >> 2;
	oct2 = 128 | uchar;
	write(1, &oct1, 1);
	write(1, &oct2, 1);
}

void			ft_putchar(char c)
{
	if (c < 0)
		print_utf(c);
	else
		write(1, &c, 1);
}
