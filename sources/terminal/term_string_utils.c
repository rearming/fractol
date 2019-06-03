/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_string_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 17:58:35 by sleonard          #+#    #+#             */
/*   Updated: 2019/06/03 09:34:21 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		update_backup(t_mlx *mlx)
{
	int		i;

	i = 9;
	while (i > 0)
	{
		ft_memcpy(mlx->term.prev_cmd[i], mlx->term.prev_cmd[i - 1], 100);
		i--;
	}
	ft_memcpy(mlx->term.prev_cmd[i], mlx->term.buff, 100);
}

void		check_backup(t_mlx *mlx, int key)
{
	if (key == ARR_UP && mlx->term.cmd_i < 10
		&& mlx->term.prev_cmd[mlx->term.cmd_i][0])
		mlx->term.cmd_i++;
	if (key == ARR_DOWN && mlx->term.cmd_i > 0)
		mlx->term.cmd_i--;
	if (mlx->term.cmd_i && mlx->term.prev_cmd[mlx->term.cmd_i][0])
	{
		ft_memcpy(mlx->term.buff, mlx->term.prev_cmd[mlx->term.cmd_i], 100);
		mlx->term.i = ft_strlen(mlx->term.buff);
	}
}

void		del_char(t_mlx *mlx)
{
	mlx->term.buff[mlx->term.i] = 0;
	mlx->term.buff[mlx->term.i - 1] = 0;
	mlx->term.i -= 2;
	mlx->term.cmd_i = 0;
}

void		clear_command_data(t_mlx *mlx)
{
	mlx->term.cmd.status = 0;
	mlx->term.cmd.action = 0;
	mlx->term.cmd.jump_area = 0;
	ft_bzero(mlx->term.buff, mlx->term.i);
	mlx->term.i = 0;
}
