/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:48:01 by sleonard          #+#    #+#             */
/*   Updated: 2019/06/02 16:31:34 by rearming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		command_based_render(t_mlx *mlx)
{
	t_command	cmd;

	cmd = mlx->term.cmd;
	mlx->frac_type = mlx->term.cmd.frac_type;
	if (cmd.action == RENDER || cmd.action == RESET)
		render_fractal(mlx, NULL);
	if (cmd.action == SET || cmd.action == JUMP)
	{
		if (mlx->frac_type == MANDELBROT)
		{
			if (cmd.jump_area == MAELSTORM)
				jump_maelstorm(mlx);
			if (cmd.jump_area == STAR_PIXEL)
				jump_star(mlx);
			if (cmd.jump_area == DEEP_SELF)
				jump_deep_self(mlx);
			if (cmd.jump_area == HOME)
				jump_home(mlx);
			key_change_mandelbrot(mlx, 0);
		}
		if (mlx->frac_type == JULIA)
			key_change_julia(mlx, 0);
		if (mlx->frac_type == TRIA)
			key_change_tria(mlx, 0);
	}
}

void		change_max_iters(t_mlx *mlx)
{
	char	*p_str;

	p_str = ft_strstr(mlx->term.buff, " iter ");
	p_str = !p_str ? ft_strstr(mlx->term.buff, " iters") : p_str;
	if (p_str)
	{
		if (mlx->term.cmd.frac_type == MANDELBROT)
			mlx->mp.max_iters = ft_atoi(p_str + 6);
		if (mlx->term.cmd.frac_type == JULIA)
			mlx->jul.max_iters = ft_atoi(p_str + 6);
		if (mlx->term.cmd.frac_type == TRIA)
			mlx->tria.r_calls = ft_atoi(p_str + 6) < 15 ?
					ft_atoi(p_str + 6) : 3;
	}
}

void		get_fractal_type(t_mlx *mlx)
{
	char 	*buff;

	buff = mlx->term.buff;
	if (ft_strstr(buff, " julia") && mlx->term.cmd.action != SET)
		mlx->term.cmd.frac_type = JULIA;
	if ((ft_strstr(buff, " mandelbrot") || ft_strstr(buff, " mandel"))
		&& mlx->term.cmd.action != SET)
	{
		mlx->is_burn = 0;
		mlx->term.cmd.frac_type = MANDELBROT;
	}
	if (ft_strstr(buff, " tria") && mlx->term.cmd.action != SET)
		mlx->term.cmd.frac_type = TRIA;
	if (ft_strstr(buff, " burning"))
	{
		mlx->term.cmd.frac_type = MANDELBROT;
		mlx->is_burn = TRUE;
	}
}
