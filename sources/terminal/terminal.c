/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:48:01 by sleonard          #+#    #+#             */
/*   Updated: 2019/06/02 11:43:29 by rearming         ###   ########.fr       */
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

void		process_colors(t_mlx *mlx)
{
	char	*buff;
	char	*p_str;

	buff = mlx->term.buff;
	if ((p_str = ft_strstr(buff, " red ")))
		mlx->rand[3] = ft_abs(ft_atoi(p_str + 4));
	if ((p_str = ft_strstr(buff, " green ")))
		mlx->rand[4] = ft_abs(ft_atoi(p_str + 6));
	if ((p_str = ft_strstr(buff, " blue ")))
		mlx->rand[5] = ft_abs(ft_atoi(p_str + 5));
	if (ft_strstr(buff, " default") || ft_strstr(buff, " random"))
	{
		mlx->rand[3] = 48;
		mlx->rand[4] = 9;
		mlx->rand[5] = 16;
		if (ft_strstr(buff, " random"))
		{
			mlx->rand[0] = random() % (9 - 2) + 2;
			mlx->rand[1] = random() % (9 - 2) + 2;
			mlx->rand[2] = random() % (9 - 2) + 2;
		}
		mlx->rand[0] = 4;
		mlx->rand[1] = 8;
		mlx->rand[2] = 16;
	}
}

void		process_jump(t_mlx *mlx)
{
	char	*buff;

	buff = mlx->term.buff;
	mlx->term.cmd.action = JUMP;
	if (ft_strstr(buff, " deepself") || ft_strstr(buff, " self"))
		mlx->term.cmd.jump_area = DEEP_SELF;
	if (ft_strstr(buff, " starpixel") || ft_strstr(buff, " star"))
		mlx->term.cmd.jump_area = STAR_PIXEL;
	if (ft_strstr(buff, " maelstorm") || ft_strstr(buff, " mael"))
		mlx->term.cmd.jump_area = MAELSTORM;
	if (ft_strstr(buff, " home"))
		mlx->term.cmd.jump_area = HOME;
}

void		process_command(t_mlx *mlx)
{
	char	*buff;

	buff = mlx->term.buff;
	mlx->term.cmd.frac_type = mlx->frac_type;
	if (ft_strstr(buff, " render "))
		mlx->term.cmd.action = RENDER;
	if (ft_strstr(buff, " set "))
		mlx->term.cmd.action = SET;
	if (ft_strstr(buff, "reset"))
		mlx->term.cmd.action = RESET;
	if (ft_strstr(buff, " jump "))
		process_jump(mlx);
	process_colors(mlx);
	if (ft_strstr(buff, " julia") && mlx->term.cmd.action != SET)
		mlx->term.cmd.frac_type = JULIA;
	if ((ft_strstr(buff, " mandelbrot") || ft_strstr(buff, " mandel"))
		&& mlx->term.cmd.action != SET)
		mlx->term.cmd.frac_type = MANDELBROT;
	if (ft_strstr(buff, " tria") && mlx->term.cmd.action != SET)
		mlx->term.cmd.frac_type = TRIA;
	if (mlx->term.cmd.action == SET)
		change_max_iters(mlx);
	ft_strstr(buff, "help") ? terminal_info(mlx) : 0;
	command_based_render(mlx);
	clear_command_data(mlx);
}
