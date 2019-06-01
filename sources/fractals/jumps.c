/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jumps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:24:15 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/31 12:08:01 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "structs.h"

void		jump_home(t_mlx *mlx)
{
	mlx->mp.scale_x = (double)WIN_WIDTH / WIN_HEIGHT;
	mlx->mp.scale_y = (double)WIN_HEIGHT / WIN_WIDTH;
	mlx->mp.max_iters = 200;
	mlx->mp.hor_shift = -2.15;
	mlx->mp.vert_shift = -0.95;
	mlx->mp.xside = 2.0 * mlx->mp.scale_x;
	mlx->mp.yside = 2.0 * mlx->mp.scale_y;
	mlx->mp.xscale = mlx->mp.xside / WIN_WIDTH;
	mlx->mp.yscale = mlx->mp.yside / WIN_HEIGHT;
}

void		jump_deep_self(t_mlx *mlx)
{
	mlx->frac_type = MANDELBROT;
	mlx->mp.max_iters = 1000;
	mlx->mp.hor_shift = -1.7433419064;
	mlx->mp.vert_shift = 0.0000907670;
	mlx->mp.xside = 0.00000000374 * mlx->mp.scale_x;
	mlx->mp.yside = 0.00000000374 * mlx->mp.scale_y;
}

void		jump_star(t_mlx *mlx)
{
	mlx->frac_type = MANDELBROT;
	mlx->mp.max_iters = 10000;
	mlx->mp.hor_shift = -0.777807810193171;
	mlx->mp.vert_shift = 0.131645108003206;
	mlx->mp.xside = 3.2 * 0.000000000000001 * mlx->mp.scale_x;
	mlx->mp.yside = 3.2 * 0.000000000000001 * mlx->mp.scale_y;
}

void		jump_maelstorm(t_mlx *mlx)
{
	mlx->frac_type = MANDELBROT;
	mlx->mp.max_iters = 500;
	mlx->mp.hor_shift = -1.96680095;
	mlx->mp.vert_shift = 0.00000478;
	mlx->mp.xside = 0.00000014 * mlx->mp.scale_x;
	mlx->mp.yside = 0.00000014 * mlx->mp.scale_y;
}
