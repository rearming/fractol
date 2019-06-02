/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:34:57 by sleonard          #+#    #+#             */
/*   Updated: 2019/06/02 11:43:29 by rearming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		raise_error(int code)
{
	if (code == ERR_INV_ARGS)
		perror("Number of args isn't 1.\n");
	if (code == ERR_INV_FILE)
		perror("Invalid file.\n");
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
	ft_printf("\nUsage: ./fractol [fractal type]\n");
	ft_printf("\tOptions:\n");
	ft_printf("\t\t ./fractol mandelbrot\n");
	ft_printf("\t\t ./fractol julia\n");
	ft_printf("\t\t ./fractol triangle\n");
	ft_printf("\t\t ./fractol burningship\n");
	ft_printf("\n");
	ft_printf("Type 'shift + :' to open fractol's terminal.\n");
	ft_printf("\tType 'help' in fractol's terminal"
		"to see options/usage of terminal.\n");
}
