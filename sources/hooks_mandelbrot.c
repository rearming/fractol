/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:03:13 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/28 19:18:58 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		key_change_mandelbrot(t_mlx *mlx, int key_code)
{
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
		mlx->mp.hor_shift += (mlx->mp.xside * 0.05) / round(mlx->mp.scale_x);
		mlx->mp.vert_shift += (mlx->mp.yside * 0.05) / round((mlx->mp.scale_y * 2));
	}
	if (key_code == NUM_MINUS)
	{
		mlx->mp.xside += mlx->mp.xside * 0.05;
		mlx->mp.yside += mlx->mp.yside * 0.05;
		mlx->mp.hor_shift -= (mlx->mp.xside * 0.05) / round(mlx->mp.scale_x);
		mlx->mp.vert_shift -= (mlx->mp.yside * 0.05) / round((mlx->mp.scale_y * 2));
	}
	if (key_code == ARR_UP)
		mlx->mp.vert_shift -= (mlx->mp.yside * 0.02);
	if (key_code == ARR_DOWN)
		mlx->mp.vert_shift += (mlx->mp.yside * 0.02);
	if (key_code == ARR_LEFT)
		mlx->mp.hor_shift -= (mlx->mp.xside * 0.02);
	if (key_code == ARR_RIGHT)
		mlx->mp.hor_shift += (mlx->mp.xside * 0.02);
	mlx->mp.xscale = (mlx->mp.xside / WIN_WIDTH);
	mlx->mp.yscale = (mlx->mp.yside / WIN_HEIGHT);
	mandelbrot_render(mlx);
}
