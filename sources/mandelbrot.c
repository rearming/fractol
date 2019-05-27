/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:48:09 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/27 20:11:23 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <colors.h>


void			set_def_mand_params(t_mlx *mlx)
{
	mlx->mode = MANDELBROT;

	mlx->rand[0] = 4;
	mlx->rand[1] = 8;
	mlx->rand[2] = 16;

	mlx->max_iters = 200;
	mlx->mp.left = -2.15;
	mlx->mp.top = -1.15;
	mlx->mp.xside = 4.5;
	mlx->mp.yside = 3.0;
	mlx->mp.xscale = mlx->mp.xside / WIN_WIDTH;
	mlx->mp.yscale = mlx->mp.yside / WIN_HEIGHT;
}

#include <ranlib.h>

int 			get_color(int iters, t_mlx *mlx)
{
	int color;
	int red;
	int green;
	int blue;

	/*red = color >> 16 & 0xFF * (ft_abs(((long double)(iters - mlx->max_iters) / mlx->max_iters) * 255));
	green = color >> 8 & 0xFF * (ft_abs(((long double)(iters - mlx->max_iters) / mlx->max_iters) * 255));
	blue = color & 0xFF * (ft_abs(((long double)(iters - mlx->max_iters) / mlx->max_iters) * 255));*/

	/*red = mlx->max_iters - iters;
	green = mlx->max_iters - iters;
	blue = mlx->max_iters - iters;*/

	/*red = 255 - 13 * iters;
	green = 255 - 9 * iters;
	blue = 255 - 7 * iters;*/

/*	red = iters % mlx->rand[0] * 64;
	green = iters % mlx->rand[1] * 32;
	blue = iters % mlx->rand[2] * 16;*/

	if (iters == mlx->max_iters)
		return (BLACK);
	red = iters % mlx->rand[0] * 64;
	green = iters % mlx->rand[1] * 32;
	blue = iters % mlx->rand[2] * 16;

	return (red << 16 | green << 8 | blue);
}

void			calc_mandelbrot(t_point curr, t_mlx *mlx)
{
	long double		temp;
	long double		zx;
	long double		zy;
	long double		cx;
	long double		cy;
	int 			iters;
	t_point			res;

	res = (t_point){curr.x, curr.y, 0, 1};
	cx = curr.x * mlx->mp.xscale + mlx->mp.left;
	cy = curr.y * mlx->mp.yscale + mlx->mp.top;
	zx = 0;
	zy = 0;
	iters = 0;
	while (zx * zx + zy * zy < 4 && iters < mlx->max_iters)
	{
		temp = zx * zx - zy * zy + cx;
		zy = 2 * zx * zy + cy;
		zx = temp;
		iters++;
	}
	res.color = get_color(iters, mlx);
	image_put_pixel(mlx->img, res, res.color);
}

void			mandelbrot(t_mlx *mlx)
{
	t_point		curr;

	curr = (t_point){0, 0, 0, 0};
	curr.x = 0;
	//put_cl_args(mlx);
	//clNDRRangeKernel(10348031581305, WIN_HEIGHT * WIN_WIDTH);
	while (curr.x <= WIN_WIDTH)
	{
		curr.y = 0;
		while (curr.y <= WIN_HEIGHT)
		{
			calc_mandelbrot(curr, mlx);
			curr.y++;
		}
		curr.x++;
	}
}
