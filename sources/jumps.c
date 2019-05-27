/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jumps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:24:15 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/27 12:23:52 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		jump_to_left(t_mlx *mlx)
{
	mlx->mode = MANDELBROT;

	mlx->mp.max_iters = 100;
	mlx->mp.left = -1.261241;
	mlx->mp.top = -0.127016;
	mlx->mp.xside = 0.0179815;
	mlx->mp.yside = 0.0179815;
}

void		jump_mandel(t_mlx *mlx)
{
	mlx->mode = MANDELBROT;

	mlx->mp.max_iters = 2000;
	mlx->mp.left = -1.7433419064;
	mlx->mp.top = 0.0000907670;
	mlx->mp.xside = 0.00000000374;
	mlx->mp.yside = 0.00000000374;
}

void		jump_star(t_mlx *mlx)
{
	mlx->mode = MANDELBROT;

	mlx->mp.max_iters = 10000;
	mlx->mp.left = -0.777807810193171;
	mlx->mp.top = 0.131645108003206;
	mlx->mp.xside = 3.2 * 0.000000000000001;
	mlx->mp.yside = 3.2 * 0.000000000000001;
}