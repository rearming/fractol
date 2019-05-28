/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:48:09 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/28 18:49:48 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "structs.h"

#include <colors.h>


void			set_def_mand_params(t_mlx *mlx)
{
	mlx->mode = MANDELBROT;

	mlx->rand[0] = 4;
	mlx->rand[1] = 8;
	mlx->rand[2] = 16;

	mlx->render_mode = GPU_RENDER;
	mlx->mp.scale_x = (double)WIN_WIDTH / WIN_HEIGHT;
	mlx->mp.scale_y = (double)WIN_HEIGHT / WIN_WIDTH;
	mlx->mp.max_iters = 200;
	mlx->mp.left = -2.15;
	mlx->mp.top = -1.15;
	mlx->mp.xside = 2.0 * mlx->mp.scale_x;
	mlx->mp.yside = 2.0 * mlx->mp.scale_y;
	mlx->mp.xscale = mlx->mp.xside / WIN_WIDTH;
	mlx->mp.yscale = mlx->mp.yside / WIN_HEIGHT;
}

int 			get_color(int iters, t_mlx *mlx)
{
	int red;
	int green;
	int blue;

	if (iters == mlx->mp.max_iters)
		return (BLACK);
	red = iters % mlx->rand[0] * 64;
	green = iters % mlx->rand[1] * 32;
	blue = iters % mlx->rand[2] * 16;
	return (red << 16 | green << 8 | blue);
}

void			calc_mandelbrot(t_point curr, t_mlx *mlx)
{
	double			temp;
	double			zx;
	double			zy;
	double			cx;
	double			cy;
	int 			iters;
	t_point			res;

	res = (t_point){curr.x, curr.y, 0, 0};
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
	res.color = get_color(iters, mlx);
	image_put_pixel(mlx->img, res, res.color);
}

void			mandelbrot(t_mlx *mlx)
{
	t_point		curr;

	curr = (t_point){0, 0, 0, 0};
	curr.x = 0;

	while (curr.x < WIN_WIDTH)
	{
		curr.y = 0;
		while (curr.y < WIN_HEIGHT)
		{
			calc_mandelbrot(curr, mlx);
			curr.y++;
		}
		curr.x++;
	}
}
