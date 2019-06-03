/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:44:12 by sleonard          #+#    #+#             */
/*   Updated: 2019/06/03 09:34:21 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom_julia(t_mlx *mlx, int mode, int source)
{
	if (mode == IN)
	{
		mlx->jul.scale -= mlx->jul.scale * 0.05;
		if (source == MOUSE)
		{
			mlx->jul.hor_shift -= (int)(mlx->jul.scale * mlx->jul.x_zoom * 40);
			mlx->jul.vert_shift -= (int)(mlx->jul.scale * mlx->jul.y_zoom * 80);
		}
	}
	if (mode == OUT)
		mlx->jul.scale += mlx->jul.scale * 0.05;
}

void		mouse_change_julia(t_mlx *mlx, t_point pos)
{
	if (!mlx->jul.is_frozen)
	{
		mlx->jul.c_part.x = (double)pos.x / WIN_WIDTH;
		mlx->jul.c_part.y = (double)pos.y / WIN_HEIGHT;
		julia_render(mlx);
	}
	pos.x = pos.x >= WIN_WIDTH / 2 ?
			pos.x - (WIN_WIDTH - pos.x) : -WIN_WIDTH + pos.x;
	pos.y = pos.y >= WIN_HEIGHT / 2 ?
			pos.y - (WIN_HEIGHT - pos.y) : -WIN_HEIGHT + pos.y;
	mlx->jul.x_zoom = (pos.x / ((double)WIN_WIDTH / 2));
	mlx->jul.y_zoom = (pos.y / ((double)WIN_HEIGHT / 2));
}

void		mouse_action_julia(t_mlx *mlx, int button_code)
{
	if (button_code == SCROLL_UP || button_code == SCROLL_DOWN)
		zoom_julia(mlx, button_code == SCROLL_UP ? IN : OUT, MOUSE);
	julia_render(mlx);
}

void		key_change_julia(t_mlx *mlx, int key_code)
{
	if (key_code == SPACE)
		mlx->jul.is_frozen = mlx->jul.is_frozen == TRUE ? FALSE : TRUE;
	if (key_code == G)
		mlx->rend_device = GPU_RENDER;
	if (key_code == C)
		mlx->rend_device = CPU_RENDER;
	if (key_code == R)
	{
		mlx->rand[0] = random() % (9 - 2) + 2;
		mlx->rand[1] = random() % (9 - 2) + 2;
		mlx->rand[2] = random() % (9 - 2) + 2;
	}
	if (key_code == N)
		set_def_julia_params(mlx);
	if (key_code == NUM_PLUS || key_code == NUM_MINUS)
		zoom_julia(mlx, key_code == NUM_PLUS ? IN : OUT, 0);
	if (key_code == ARR_UP)
		mlx->jul.vert_shift += (int)round((mlx->jul.scale * 60));
	if (key_code == ARR_DOWN)
		mlx->jul.vert_shift -= (int)round((mlx->jul.scale * 60));
	if (key_code == ARR_LEFT)
		mlx->jul.hor_shift += (int)round((mlx->jul.scale * 30));
	if (key_code == ARR_RIGHT)
		mlx->jul.hor_shift -= (int)round((mlx->jul.scale * 30));
	julia_render(mlx);
}
