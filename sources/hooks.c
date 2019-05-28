/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:10:27 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/28 16:53:50 by sleonard         ###   ########.fr       */
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
	|| keycode == C || keycode == G || keycode == SPACE)
		return (1);
	return (0);
}

int 		cross_hook(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int			mouse_move(int x, int y, void *param)
{
	t_mlx		*mlx;

	mlx = (t_mlx*)param;
	if (mlx->mode == JULIA && !mlx->jul.is_frozen)
		mouse_change_julia(mlx, (t_point){x, y, 0, 0});
	return (0);
}

int 		key_hook(int key_code, void *param)
{
	t_mlx		*mlx;

	mlx = (t_mlx*)param;
	//printf("key code: [%i]\n", key_code);
	if (key_code == ESC)
		exit(0);
	if (mlx->mode == MANDELBROT && is_action_key(key_code))
		key_change_mandelbrot(mlx, key_code);
	if (mlx->mode == JULIA && is_action_key(key_code))
		key_change_julia(mlx, key_code);
	return (0);
}