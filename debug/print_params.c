/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:42:33 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/27 16:01:38 by sleonard         ###   ########.fr       */
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
	printf("\t\nCOLOR'S MODS:\n");
	printf("red: [%i]\n", mlx->rand[0]);
	printf("green: [%i]\n", mlx->rand[1]);
	printf("blue: [%i]\n", mlx->rand[2]);
}

void		print_params(t_mlx *mlx)
{
	if (mlx->mode == MANDELBROT)
		print_mandel_params(mlx);

}