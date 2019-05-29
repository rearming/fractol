/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:44:12 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/29 16:02:50 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom_julia(t_mlx *mlx, int mode)
{
	int 		new_hor_shift;
	int 		new_vert_shift;

	new_hor_shift = (int)(1000 / (double)(20 / mlx->jul.x_zoom) * mlx->jul.scale);
	new_vert_shift = (int)(1000 / (double)(20 / mlx->jul.y_zoom) * mlx->jul.scale);
	if (mode == IN)
	{
		mlx->jul.scale -= mlx->jul.scale * 0.05;
		mlx->jul.hor_shift -= new_hor_shift;
		mlx->jul.vert_shift -= new_vert_shift;
	}
	if (mode == OUT)
	{
		mlx->jul.scale += mlx->jul.scale * 0.05;
		mlx->jul.hor_shift += new_hor_shift;
		mlx->jul.vert_shift += new_vert_shift;
		/*mlx->jul.hor_shift -= (int)(mlx->jul.scale_x * mlx->jul.x_zoom * 10);
		mlx->jul.vert_shift -= (int)(mlx->jul.scale_y * 1 * mlx->jul.y_zoom * 10);*/
	}
	printf("x zoom: [%f]\n", mlx->jul.x_zoom);
	printf("y zoom: [%f]\n", mlx->jul.y_zoom);
	printf("scale: [%f]\n", mlx->jul.scale);
	printf("scale change: [%f]\n", mlx->jul.scale * 0.05);
	printf("hor shift change: [%i]\n", new_hor_shift);
	printf("vert shift change: [%i]\n", new_vert_shift);

	printf("HOR SHIFT: [%i]\n", mlx->jul.hor_shift);
	printf("VERT SHIFT: [%i]\n", mlx->jul.vert_shift);
	printf("\n");
}

void		mouse_change_julia(t_mlx *mlx, t_point pos)
{
	if (!mlx->jul.is_frozen)
	{
		mlx->jul.c_part.x = (double) pos.x / WIN_WIDTH;
		mlx->jul.c_part.y = (double) pos.y / WIN_HEIGHT;
		julia_render(mlx);
	}
	pos.x = pos.x >= WIN_WIDTH / 2 ? pos.x - (WIN_WIDTH - pos.x) : -WIN_WIDTH + pos.x;
	pos.y = pos.y >= WIN_HEIGHT / 2 ? pos.y - (WIN_HEIGHT - pos.y) : -WIN_HEIGHT + pos.y;

	mlx->jul.x_zoom = (pos.x / ((double)WIN_WIDTH / 2));
	mlx->jul.y_zoom = (pos.y / ((double)WIN_HEIGHT / 4));
}

void		mouse_action_julia(t_mlx *mlx, int button_code)
{
	if (button_code == SCROLL_UP || button_code == SCROLL_DOWN)
		zoom_julia(mlx, button_code == SCROLL_UP ? IN : OUT);
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
	if (key_code == N)
		set_def_julia_params(mlx);
	if (key_code == NUM_PLUS || key_code == NUM_MINUS)
		zoom_julia(mlx, key_code == NUM_PLUS ? IN : OUT);

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
