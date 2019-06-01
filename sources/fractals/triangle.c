/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:13:00 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/31 20:01:53 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_def_triangle_params(t_mlx *mlx)
{
	mlx->frac_type = TRIA;
	mlx->tria.r_calls = 6;
	mlx->tria.color = LIGHT_BLUE;
	mlx->tria.pos_top.x = WIN_WIDTH / 2;
	mlx->tria.pos_top.y = WIN_HEIGHT - (WIN_HEIGHT - 50);
	mlx->tria.side = 1100;
}

void		r_triangle(t_mlx *mlx, t_point top, int len, int r_calls)
{
	t_point		bot1;
	t_point		bot2;

	if (!r_calls)
		return ;
	bot1 = top;
	bot2 = top;
	bot1.x -= len / 2;
	bot2.x += len / 2;
	bot1.y += len;
	bot2.y += len;
	bresen_line(mlx, bot1, bot2);
	bresen_line(mlx, bot1, top);
	bresen_line(mlx, bot2, top);
	len /= 2;
	r_calls--;
	top.color = V_RED;
	r_triangle(mlx, top, len, r_calls);
	top.x -= len / 2;
	top.y += len;
	top.color = PURPLE;
	r_triangle(mlx, top, len, r_calls);
	top.x += len;
	top.color = WHITE;
	r_triangle(mlx, top, len, r_calls);
}

void		triangle(t_mlx *mlx)
{
	t_point		top;
	int			side;

	side = mlx->tria.side;
	top = mlx->tria.pos_top;
	top.color = mlx->tria.color;
	r_triangle(mlx, top, side, mlx->tria.r_calls);
}
