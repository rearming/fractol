/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:42:33 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/31 12:08:01 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "structs.h"

void		print_mandel_params(t_mlx *mlx)
{
	printf("\n---------------------\n");
	printf("MANDELBROT'S PARAMS:\n\n");
	printf("hor_shift: [%.*f]\n", 20, mlx->mp.hor_shift);
	printf("vert_shift: [%.*f]\n", 20, mlx->mp.vert_shift);
	printf("X side: [%.*f]\n", 20, mlx->mp.xside);
	printf("Y side: [%.*f]\n", 20, mlx->mp.yside);
	printf("\t\nSCALE:\n");
	printf("X scale: [%f]\n", mlx->mp.xscale);
	printf("Y scale: [%f]\n", mlx->mp.yscale);
	printf("\t\nCOLOR'S MODS:\n");
	printf("red: [%i]\n", mlx->rand[0]);
	printf("green: [%i]\n", mlx->rand[1]);
	printf("blue: [%i]\n", mlx->rand[2]);
	printf("red coeff: [%i]\n", mlx->rand[3]);
	printf("green coeff: [%i]\n", mlx->rand[4]);
	printf("blue coeff: [%i]\n", mlx->rand[5]);
	printf("\t\nMAX ITERS:\n");
	printf("[%i]\n", mlx->mp.max_iters);
}

void		print_params(t_mlx *mlx)
{
	if (mlx->frac_type == MANDELBROT)
		print_mandel_params(mlx);
}