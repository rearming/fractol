/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:54:48 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/27 18:54:44 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char		*cl_gnl(int fd)
{
	t_gnl_fdf	gnl;

	gnl.sum_len = 0;
	gnl.backup = ft_memalloc(1);
	gnl.temp_str = NULL;
	if (fd < 0 || read(fd, gnl.buf, 0) < 0)
		raise_error(ERR_INV_FILE);
	while ((gnl.read_res = read(fd, gnl.buf, CL_BUFF_SIZE)))
	{
		gnl.sum_len += gnl.read_res;
		gnl.buf[gnl.read_res] = '\0';
		gnl.temp_str = ft_strljoin(gnl.backup, gnl.buf, gnl.sum_len);
		free(gnl.backup);
		gnl.backup = gnl.temp_str;
	}
	return (gnl.backup);
}
