/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:03:13 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/29 18:47:55 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom_mandelbrot(t_mlx *mlx, int mode)
{
	if (mode == IN)
	{
		mlx->mp.xside -= mlx->mp.xside * 0.05;
		mlx->mp.yside -= mlx->mp.yside * 0.05;
		mlx->mp.hor_shift += (mlx->mp.xside * 0.05) * mlx->mp.x_zoom;
		mlx->mp.vert_shift += (mlx->mp.yside * 0.05) * mlx->mp.y_zoom;
	}
	if (mode == OUT)
	{
		mlx->mp.xside += mlx->mp.xside * 0.05;
		mlx->mp.yside += mlx->mp.yside * 0.05;
		mlx->mp.hor_shift -= (mlx->mp.xside * 0.05) / round(mlx->mp.scale_x);
		mlx->mp.vert_shift -= (mlx->mp.yside * 0.05) / round((mlx->mp.scale_y * 2));
	}
}

void		key_change_mandelbrot(t_mlx *mlx, int key_code)
{
	if (key_code == G)
		mlx->rend_device = GPU_RENDER;
	if (key_code == C)
		mlx->rend_device = CPU_RENDER;
	if (key_code == J)
	{
		//jump_to_left(mlx);
		jump_mandel(mlx);
		//jump_star(mlx);
		//jump_maelstorm(mlx);
	}
	if (key_code == R)
	{
		mlx->rand[0] = random() % (9 - 2) + 2;
		mlx->rand[1] = random() % (9 - 2) + 2;
		mlx->rand[2] = random() % (9 - 2) + 2;
	}
	if (key_code == N)
		set_def_mand_params(mlx);
	if (key_code == NUM_PLUS || key_code == NUM_MINUS)
		zoom_mandelbrot(mlx, key_code == NUM_PLUS ? IN : OUT);

	if (key_code == ARR_UP)
		mlx->mp.vert_shift -= (mlx->mp.yside * 0.02);
	if (key_code == ARR_DOWN)
		mlx->mp.vert_shift += (mlx->mp.yside * 0.02);
	if (key_code == ARR_LEFT)
		mlx->mp.hor_shift -= (mlx->mp.xside * 0.02);
	if (key_code == ARR_RIGHT)
		mlx->mp.hor_shift += (mlx->mp.xside * 0.02);
	mandelbrot_render(mlx);
}

void		mouse_action_mandelbrot(t_mlx *mlx, int button_code)
{
	if (button_code == SCROLL_UP || button_code == SCROLL_DOWN)
		zoom_mandelbrot(mlx, button_code == SCROLL_UP ? IN : OUT);
	mandelbrot_render(mlx);
}

void		mouse_change_mandelbort(t_point pos, t_mlx *mlx)
{
	pos.x = pos.x >= WIN_WIDTH / 2 ? pos.x - (WIN_WIDTH - pos.x) : -WIN_WIDTH / 2 + pos.x;
	pos.y = pos.y >= WIN_HEIGHT / 2 ? pos.y - (WIN_HEIGHT - pos.y) : -WIN_HEIGHT / 2 + pos.y;

	mlx->mp.x_zoom = (pos.x / ((double)WIN_WIDTH / 2)) + 0.5;
	mlx->mp.y_zoom = (pos.y / ((double)WIN_HEIGHT / 4)) + 0.5;
}
