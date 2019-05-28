/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:44:12 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/28 19:51:18 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mouse_change_julia(t_mlx *mlx, t_point pos)
{
	mlx->jul.c_part.x = (double) pos.x / WIN_WIDTH;
	mlx->jul.c_part.y = (double) pos.y / WIN_HEIGHT;
	julia_render(mlx);
}

void		key_change_julia(t_mlx *mlx, int key_code)
{
	if (key_code == SPACE)
		mlx->jul.is_frozen = mlx->jul.is_frozen == TRUE ? FALSE : TRUE;
	if (key_code == G)
		mlx->render_mode = GPU_RENDER;
	if (key_code == C)
		mlx->render_mode = CPU_RENDER;
	if (key_code == R)
	{
		mlx->rand[0] = random() % (9 - 2) + 2;
		mlx->rand[1] = random() % (9 - 2) + 2;
		mlx->rand[2] = random() % (9 - 2) + 2;
	}
	if (key_code == NUM_PLUS)
	{
		mlx->jul.scale -= mlx->jul.scale * 0.05;
		/*mlx->jul.hor_shift += (int)((mlx->jul.scale_x) * 20);
		mlx->jul.vert_shift += (int)((mlx->jul.scale_y) * 10);*/
	}
	if (key_code == NUM_MINUS)
	{
		mlx->jul.scale += mlx->jul.scale * 0.05;
	}
	if (key_code == ARR_UP)
		mlx->jul.vert_shift += 50;
	if (key_code == ARR_DOWN)
		mlx->jul.vert_shift -= 50;
	if (key_code == ARR_LEFT)
		mlx->jul.hor_shift += 50;
	if (key_code == ARR_RIGHT)
		mlx->jul.hor_shift -= 50;
	julia_render(mlx);
}
