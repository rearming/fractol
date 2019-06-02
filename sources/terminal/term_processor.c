/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_processor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rearming <rearming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 16:21:43 by rearming          #+#    #+#             */
/*   Updated: 2019/06/02 16:21:43 by rearming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	get_fractal_type(mlx);
	if (mlx->term.cmd.action == SET)
		change_max_iters(mlx);
	if (ft_strstr(buff, "help"))
		terminal_info(mlx);
	command_based_render(mlx);
	clear_command_data(mlx);
}
