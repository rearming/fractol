/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:56:11 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/29 11:52:43 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		render_fractal(t_mlx *mlx, char *name)
{
	if (ft_strstr(name, "mandelbrot"))
	{
		set_def_mand_params(mlx);
		mlx->cl = cl_init(mlx);
		mandelbrot_render(mlx);
	}
	if (ft_strstr(name, "julia"))
	{
		set_def_julia_params(mlx);
		mlx->cl = cl_init(mlx);
		julia_render(mlx);
	}
}

int 		main(int argc, char **argv)
{
	t_mlx		*mlx;

	mlx = ft_mlx_init();
	if (argc != 2)
		raise_error(ERR_USAGE);
	render_fractal(mlx, argv[1]);
	mlx_hook(mlx->win, 2, 0, &key_hook, mlx);
	mlx_hook(mlx->win, 6, 0, &mouse_move, mlx);
	mlx_hook(mlx->win, 4, 0, &mouse_action, mlx);
	mlx_hook(mlx->win, 17, 0, &cross_hook, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}