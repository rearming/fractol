/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:34:57 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/27 10:01:15 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		raise_error(int code)
{
	if (code == ERR_INV_ARGS)
		perror("Number of args isn't 1.\n");
	if (code == ERR_INV_FILE)
		perror("Invalid file.\n");
	if (code == ERR_INV_MAP)
		ft_printf("Valid map contains only numbers and whitespaces!\n");
	if (code == ERR_MALLOC)
		ft_printf("Malloc failed.\n");
	if (code == ERR_MLX_INIT)
		ft_printf("Mlx init failed.\n");
	if (code == ERR_USAGE)
		show_usage();
	if (code == ERR_OPENCL)
		ft_printf("Open CL initialisation fails.\n");
	exit(code);
}

void		show_usage(void)
{
	ft_printf("Usage: ./fractol [fractal type]\n");
	ft_printf("\tFor example: ./fractol mandelbrot");
}