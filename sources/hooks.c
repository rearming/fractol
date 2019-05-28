/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:10:27 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/28 12:26:45 by sleonard         ###   ########.fr       */
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
	|| keycode == J || keycode == R
	|| keycode == C || keycode == G)
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
	clear_image(mlx);
	if (key_code == G)
		mlx->render_mode = GPU_RENDER;
	if (key_code == C)
		mlx->render_mode = CPU_RENDER;
	if (key_code == J)
	{
		//jump_to_left(mlx);
		//jump_mandel(mlx);
		//jump_star(mlx);
		jump_maelstorm(mlx);
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
		mlx->mp.left += (mlx->mp.xside * 0.05) / 2.0;//mlx->mp.scale_x;
		mlx->mp.top += (mlx->mp.yside * 0.05) / 1;//mlx->mp.scale_y > 1 ? mlx->mp.scale_y : 1;
		//mlx->max_iters += 5;
	}
	if (key_code == NUM_MINUS)
	{
		mlx->mp.xside += mlx->mp.xside * 0.05;
		mlx->mp.yside += mlx->mp.yside * 0.05;
		mlx->mp.left -= (mlx->mp.xside * 0.05) / mlx->mp.scale_x;
		mlx->mp.top -= (mlx->mp.yside * 0.05) / mlx->mp.scale_y;
		//mlx->max_iters -= 5;
	}
	if (key_code == ARR_UP)
		mlx->mp.top -= (mlx->mp.yside * 0.02);
	if (key_code == ARR_DOWN)
		mlx->mp.top += (mlx->mp.yside * 0.02);
	if (key_code == ARR_LEFT)
		mlx->mp.left -= (mlx->mp.xside * 0.02);
	if (key_code == ARR_RIGHT)
		mlx->mp.left += (mlx->mp.xside * 0.02);
	mlx->mp.xscale = (mlx->mp.xside / WIN_WIDTH);
	mlx->mp.yscale = (mlx->mp.yside / WIN_HEIGHT);

	render(mlx, mlx->render_mode);
}

int 		key_hook(int key_code, void *param)
{
	t_mlx		*mlx;

	mlx = (t_mlx*)param;
	//printf("key code: [%i]\n", key_code);
	if (key_code == ESC)
		exit(0);
	if (mlx->mode == MANDELBROT && is_action_key(key_code))
		change_mandelbrot(mlx, key_code);
	return (0);
}