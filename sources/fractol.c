/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:56:11 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/28 12:18:48 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		render_fractal(t_mlx *mlx, char *name)
{
	if (ft_strstr(name, "mandelbrot"))
	{
		set_def_mand_params(mlx);
		render(mlx, mlx->render_mode);
		print_params(mlx);
		//mandelbrot(mlx);
		//mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	}
}

int 		main(int argc, char **argv)
{
	t_mlx		*mlx;

	mlx = ft_mlx_init();
	if (argc != 2)
		raise_error(ERR_USAGE);
	mlx->cl = cl_init(mlx);
	render_fractal(mlx, argv[1]);
	mlx_hook(mlx->win, 2, 0, &key_hook, mlx);
	mlx_hook(mlx->win, 17, 0, &cross_hook, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}