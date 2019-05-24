/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:40:51 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/13 11:19:47 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

static void		print_utf_fd(char c, int fd)
{
	unsigned char	uchar;
	unsigned char	oct1;
	unsigned char	oct2;

	uchar = (129 + c) + 127;
	oct1 = uchar >> 6;
	oct1 = oct1 ^ 192;
	uchar = uchar << 2;
	uchar = uchar >> 2;
	oct2 = 128 ^ uchar;
	write(fd, &oct1, 1);
	write(fd, &oct2, 1);
}

void			ft_putchar_fd(char c, int fd)
{
	if (c < 0)
		print_utf_fd(c, fd);
	else
		write(fd, &c, 1);
}
