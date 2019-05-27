/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:10:27 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/27 16:46:35 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int 		is_action_key(int keycode)
{
	if (keycode == ARR_UP || keycode == ARR_LEFT
	|| keycode == ARR_RIGHT || keycode == ARR_DOWN
	|| keycode == NUM_PLUS || keycode == NUM_MINUS
	|| keycode == NUM_LEFT || keycode == NUM_RIGHT
	|| keycode == NUM_UP || keycode == NUM_DOWN
	|| keycode == J || keycode == R)
		return (1);
	return (0);
}

int 		cross_hook(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void		change_mandelbrot(t_mlx *mlx, int key_code)
{
	//clear_image(mlx);
	bzero(mlx->img->data, WIN_HEIGHT * WIN_WIDTH * mlx->img->bpp);
	if (key_code == J)
	{
		jump_to_left(mlx);
		//jump_mandel(mlx);
		//jump_star(mlx);
	}
	if (key_code == R)
	{
		mlx->rand[0] = random() % (9 - 2) + 2;
		mlx->rand[1] = random() % (9 - 2) + 2;
		mlx->rand[2] = random() % (9 - 2) + 2;
	}
	if (key_code == NUM_PLUS)
	{
		mlx->mp.xside -= mlx->mp.xside * 0.05;
		mlx->mp.yside -= mlx->mp.yside * 0.05;
		mlx->mp.left += (mlx->mp.xside * 0.05) / 2.0;
		mlx->mp.top += (mlx->mp.yside * 0.05) / 2.0;
	}
	if (key_code == NUM_MINUS)
	{
		mlx->mp.xside += mlx->mp.xside * 0.05;
		mlx->mp.yside += mlx->mp.yside * 0.05;
		mlx->mp.left -= (mlx->mp.xside * 0.05) / 2;
		mlx->mp.top -= (mlx->mp.yside * 0.05) / 2;
	}
	if (key_code == ARR_UP)
		mlx->mp.top -= (mlx->mp.yside * 0.05) / 2.0;
	if (key_code == ARR_DOWN)
		mlx->mp.top += (mlx->mp.yside * 0.05) / 2.0;
	if (key_code == ARR_LEFT)
		mlx->mp.left -= (mlx->mp.xside * 0.05) / 2.0;
	if (key_code == ARR_RIGHT)
		mlx->mp.left += (mlx->mp.xside * 0.05) / 2.0;
	mlx->mp.xscale = (mlx->mp.xside / WIN_WIDTH);
	mlx->mp.yscale = (mlx->mp.yside / WIN_HEIGHT);
	mandelbrot(mlx);
	print_mandel_params(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}

int 		key_hook(int key_code, void *param)
{
	t_mlx		*mlx;

	mlx = (t_mlx*)param;
	if (key_code == ESC)
		exit(0);
	if (mlx->mode == MANDELBROT && is_action_key(key_code))
		change_mandelbrot(mlx, key_code);
	if (key_code == SPACE)
	{
		mandelbrot(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	}
	return (0);
}