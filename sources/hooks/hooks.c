/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:10:27 by sleonard          #+#    #+#             */
/*   Updated: 2019/06/03 16:20:53 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			is_action_key(int keycode)
{
	if (keycode == ARR_UP || keycode == ARR_LEFT
	|| keycode == ARR_RIGHT || keycode == ARR_DOWN
	|| keycode == NUM_PLUS || keycode == NUM_MINUS
	|| keycode == J || keycode == R || keycode == N
	|| keycode == C || keycode == G || keycode == SPACE
	|| keycode == ENTER || keycode == S)
		return (1);
	return (0);
}

int			cross_hook(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	exit_clean(mlx);
	return (0);
}

int			mouse_move(int x, int y, void *param)
{
	t_mlx		*mlx;

	mlx = (t_mlx*)param;
	if (mlx->term.cmd.status == LISTEN)
		return (0);
	if (x > WIN_WIDTH || y > WIN_HEIGHT || x < 0 || y < 0)
		return (0);
	if (mlx->frac_type == JULIA)
		mouse_change_julia(mlx, (t_point){x, y, 0, 0});
	if (mlx->frac_type == MANDELBROT)
		mouse_change_mandelbort((t_point){x, y, 0, 0}, mlx);
	return (0);
}

int			mouse_action(int button_code, void *param)
{
	t_mlx		*mlx;

	mlx = (t_mlx*)param;
	if (mlx->term.cmd.status == LISTEN)
		return (0);
	if (mlx->frac_type == MANDELBROT)
		mouse_action_mandelbrot(mlx, button_code);
	if (mlx->frac_type == JULIA)
		mouse_action_julia(mlx, button_code);
	return (0);
}

int			key_hook(int key_code, void *param)
{
	t_mlx		*mlx;

	mlx = (t_mlx*)param;
	if (key_code == ESC)
		exit_clean(mlx);
	if (key_code == SHIFT)
	{
		mlx->term.cmd.status = PREPARE;
		return (0);
	}
	if ((key_code == COLON && mlx->term.cmd.status == PREPARE)
				|| mlx->term.cmd.status == LISTEN)
	{
		parse_term_input(mlx, key_code);
		return (0);
	}
	if (mlx->frac_type == MANDELBROT && is_action_key(key_code))
		key_change_mandelbrot(mlx, key_code);
	if (mlx->frac_type == JULIA && is_action_key(key_code))
		key_change_julia(mlx, key_code);
	if (mlx->frac_type == TRIA && is_action_key(key_code))
		key_change_tria(mlx, key_code);
	return (0);
}
