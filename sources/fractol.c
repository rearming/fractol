/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:56:11 by sleonard          #+#    #+#             */
/*   Updated: 2019/06/02 12:15:51 by rearming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		render_fractal(t_mlx *mlx, char *name)
{
	clear_image(mlx);

	if (mlx->term.cmd.frac_type == MANDELBROT || ft_strstr(name, "mandelbrot"))
	{
		set_def_mand_params(mlx);
		//cl_new_program(mlx);
		cl_init(mlx);
		mandelbrot_render(mlx);
		//cl_init(mlx);
		clean_opencl(mlx);
	}
	else if (mlx->term.cmd.frac_type == JULIA || ft_strstr(name, "julia"))
	{
		set_def_julia_params(mlx);
		//cl_new_program(mlx);
		cl_init(mlx);
		julia_render(mlx);
		//clean_opencl(mlx);
		clean_opencl(mlx);
	}
	else if (mlx->term.cmd.frac_type == TRIA || ft_strstr(name, "tria"))
	{
		set_def_triangle_params(mlx);
		triangle(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
		screen_info(mlx);
		//clean_opencl(mlx);
	}
	else
		raise_error(ERR_USAGE);
}

int			main(int argc, char **argv)
{
	t_mlx		*mlx;

	if (argc != 2)
		raise_error(ERR_USAGE);
	mlx = ft_mlx_init();
	render_fractal(mlx, argv[1]);
	mlx_hook(mlx->win, 2, 1, &key_hook, mlx);
	mlx_hook(mlx->win, 4, 4, &mouse_action, mlx);
	mlx_hook(mlx->win, 17, 1, &cross_hook, mlx);
	mlx_hook(mlx->win, 6, (1L << 6), &mouse_move, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
