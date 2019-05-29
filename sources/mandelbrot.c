/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:48:09 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/29 19:40:26 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "structs.h"

#include <colors.h>


void			set_def_mand_params(t_mlx *mlx)
{
	mlx->frac_type = MANDELBROT;

	mlx->rand[0] = 4;
	mlx->rand[1] = 8;
	mlx->rand[2] = 16;

	mlx->rend_device = GPU_RENDER;
	mlx->mp.scale_x = (double)WIN_WIDTH / WIN_HEIGHT;
	mlx->mp.scale_y = (double)WIN_HEIGHT / WIN_WIDTH;
	mlx->mp.max_iters = 200;
	mlx->mp.hor_shift = -2.15;
	mlx->mp.vert_shift = -1.15;
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
	red = iters % mlx->rand[0] * 24;
	green = iters % mlx->rand[1] * 32;
	blue = iters % mlx->rand[2] * 16;
	return (red << 16 | green << 8 | blue);
}

void			calc_mandelbrot(t_point curr, t_mlx *mlx)
{
	double			temp;
	t_complex		z;
	t_complex		c;
	int 			iters;
	t_point			res;

	res = (t_point){curr.x, curr.y, 0, 0};
	c.x = curr.x * mlx->mp.xscale + mlx->mp.hor_shift;
	c.y = curr.y * mlx->mp.yscale + mlx->mp.vert_shift;
	z.x = 0;
	z.y = 0;
	iters = 0;
	while (z.x * z.x + z.y * z.y < 4 && iters < mlx->mp.max_iters)
	{
		temp = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp;
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
