/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:56:11 by sleonard          #+#    #+#             */
/*   Updated: 2019/06/11 14:09:06 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		render_fractal(t_mlx *mlx, char *name)
{
	clear_image(mlx);
	clean_opencl(mlx);
	if (mlx->term.cmd.frac_type == MANDELBROT || ft_strequ(name, "mandelbrot")
		|| ft_strequ(name, "burningship"))
	{
		set_def_mand_params(mlx);
		cl_init(mlx);
		mlx->is_burn = ft_strequ(name, "burningship") ? TRUE : mlx->is_burn;
		mandelbrot_render(mlx);
	}
	else if (mlx->term.cmd.frac_type == JULIA || ft_strequ(name, "julia"))
	{
		set_def_julia_params(mlx);
		cl_init(mlx);
		julia_render(mlx);
	}
	else if (mlx->term.cmd.frac_type == TRIA || ft_strequ(name, "triangle"))
	{
		set_def_triangle_params(mlx);
		triangle(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
		screen_info(mlx);
	}
	else
		raise_error(ERR_USAGE);
}

int			main(int argc, char **argv)
{
	t_mlx		*mlx;
	char 		*name;

	if (argc != 2)
		raise_error(ERR_USAGE);
	name = ft_strtrim(argv[1]);
	mlx = ft_mlx_init();
	render_fractal(mlx, name);
	mlx_hook(mlx->win, 2, 1, &key_hook, mlx);
	mlx_hook(mlx->win, 4, 4, &mouse_action, mlx);
	mlx_hook(mlx->win, 17, 1, &cross_hook, mlx);
	mlx_hook(mlx->win, 6, (1L << 6), &mouse_move, mlx);
	mlx_loop(mlx->mlx);
	free(name);
	return (0);
}
