/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:48:09 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/27 12:20:53 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			set_def_mand_params(t_mlx *mlx)
{
	mlx->mode = MANDELBROT;

	mlx->mp.max_iters = 100;
	mlx->mp.left = -2.35;
	mlx->mp.top = -1.15;
	//mlx->mp.left = 0;
	//mlx->mp.top = 0;
	mlx->mp.xside = 2.35;
	mlx->mp.yside = 2.35;
	mlx->mp.xscale = mlx->mp.xside / WIN_WIDTH;
	mlx->mp.yscale = mlx->mp.yside / WIN_HEIGHT;
}

void			set_mandel_params(t_mlx *mlx)
{
	mlx->mode = MANDELBROT;

	mlx->mp.xscale = mlx->mp.xside / WIN_WIDTH;
	mlx->mp.yscale = mlx->mp.yside / WIN_HEIGHT;
}

int 			get_color(int iters, t_mlx *mlx)
{
	int 	color;
	int 	red;
	int 	green;
	int 	blue;

	color = 0;
	red = RED;
	green = GREEN;
	blue = BLUE;
	/*red = color >> 16 & 0xFF;
	green = color >> 8 & 0xFF;
	blue = color & 0xFF;*/
	red = (mlx->mp.max_iters - iters);
	green = (mlx->mp.max_iters - iters);
	blue = (mlx->mp.max_iters - iters);
	/*red = 255 - (iters / mlx->mp.max_iters);
	green = 255 - (iters / mlx->mp.max_iters);
	blue = 255 - (iters / mlx->mp.max_iters);*/
	//return (iters == mlx->mp.max_iters ? BLACK : WHITE);
	return (red << 16 | green << 8 | blue);
}

void			calc_mandelbrot(t_point curr, t_mlx *mlx)
{
	long double		temp;
	long double		zx;
	long double		zy;
	long double		cx;
	long double 	cy;
	int 		iters;
	t_point		res;

	res = (t_point){curr.x, curr.y, 0, 1};
	cx = curr.x * mlx->mp.xscale + mlx->mp.left;
	cy = curr.y * mlx->mp.yscale + mlx->mp.top;
	zx = 0;
	zy = 0;
	iters = 0;
	while (zx * zx + zy * zy < 4 && iters < mlx->mp.max_iters)
	{
		temp = zx * zx - zy * zy + cx;
		zy = 2 * zx * zy + cy;
		zx = temp;
		iters++;
	}
	res.color *= get_color(iters, mlx);
	image_put_pixel(mlx->img, res, res.color);
}

void			mandelbrot(t_mlx *mlx)
{
	t_point		curr;

	curr = (t_point){0, 0, 0, 0};
	curr.x = 0;
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
