/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:42:33 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/27 11:45:14 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		print_mandel_params(t_mlx *mlx)
{
	printf("\n---------------------\n");
	printf("MANDELBROT'S PARAMS:\n\n");
	printf("left: [%.*Lf]\n", 20, mlx->mp.left);
	printf("top: [%.*Lf]\n", 20, mlx->mp.top);
	printf("X side: [%.*Lf]\n", 20, mlx->mp.xside);
	printf("Y side: [%.*Lf]\n", 20, mlx->mp.yside);
	printf("\t\nSCALE:\n");
	printf("X scale: [%Lf]\n", mlx->mp.xscale);
	printf("Y scale: [%Lf]\n", mlx->mp.yscale);
}

void		print_params(t_mlx *mlx)
{
	if (mlx->mode == MANDELBROT)
		print_mandel_params(mlx);

}