/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:42:48 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/31 20:23:16 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			terminal_info(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 25, 250, 0xA7A3D8,
		"Help message appeared in output!");
	ft_printf("\n------> FRACTOL TERMINAL'S MANUAL <-----\n\n");
	ft_printf("If you want to render specific"
		"fractal, type 'render [fractal]'\n");
	ft_printf("\tFor example: render julia\n");
	ft_printf("\n");
	ft_printf("To reset changes of current fractal, type 'reset'");
	ft_printf("\n");
	ft_printf("You can set colors channel values"
		"by running command 'set [color] [value]\n");
	ft_printf("\tYou can also specify number of max"
		"iterations: 'set iter [value]'\n");
	ft_printf("\n");
	ft_printf("You can jump to few interesting places"
		"in mandelbrot - just type 'jump [place]\n");
	ft_printf("\tAvailable places to jump: self, star, mael\n");
	ft_printf("\nCommand line has memory, like usual shell.\n"
		"Use it with arrows up and down.\n");
}

void			screen_info(t_mlx *mlx)
{
	int		color;

	color = 0xA7A3D8;
	mlx_string_put(mlx->mlx, mlx->win, 25, 5, color,
				"[fractol by Sleonard]");
	mlx_string_put(mlx->mlx, mlx->win, 25, 40, color,
				"usage:");
	mlx_string_put(mlx->mlx, mlx->win, 25, 65, color,
				"N - reset map, R - random colors,"
	" Space - freeze Julia / Increase calls of Triangle");
	mlx_string_put(mlx->mlx, mlx->win, 25, 90, color,
				"Arrows - movement, Mouse + scroll - zoom");
	mlx_string_put(mlx->mlx, mlx->win, 25, 115, color,
				"Current fractal: ");
	if (mlx->frac_type == MANDELBROT)
		mlx_string_put(mlx->mlx, mlx->win, 225, 115, color, "Mandelbrot");
	if (mlx->frac_type == JULIA)
		mlx_string_put(mlx->mlx, mlx->win, 225, 115, color, "Julia");
	if (mlx->frac_type == TRIA)
		mlx_string_put(mlx->mlx, mlx->win, 225, 115, color,
				"Sierpinski Triangle");
	mlx_string_put(mlx->mlx, mlx->win, 25, 160, color,
				"You can use built-in terminal: [Shift + :] - invocation");
	mlx_string_put(mlx->mlx, mlx->win, 25, 185, color,
				"Type 'help' to see terminal usage");
}
