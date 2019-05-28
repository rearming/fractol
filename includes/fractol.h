/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:56:23 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/28 18:59:21 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <math.h>
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <OpenCL/opencl.h>

#include "libft.h"
#include "structs.h"
#include "colors.h"
#include "key_codes.h"
#include "errors.h"
#include "defines.h"
/*
**	main
*/

void		render_fractal(t_mlx *mlx, char *name);

/*
**	init
*/

t_mlx		*ft_mlx_init(void);

/*
**	Open CL init
*/

t_cl cl_init(t_mlx *mlx);
char		*cl_gnl(int fd);


/*
**	Open CL utils
*/

void		cl_fill_mandelbrot_buffer(t_mlx *mlx);
void		cl_run_kernels(t_mlx *mlx);

/*
** Open CL render
*/

void		mandelbrot_render(t_mlx *mlx);
void		julia_render(t_mlx *mlx);
/*
**	error
*/

void		raise_error(int code);
void		show_usage(void);

/*
**	hooks utils
*/

int 		cross_hook(void *param);
int 		key_hook(int key_code, void *param);
int			mouse_move(int x, int y, void *param);
/*
**	hooks mandlelbrot
*/

void		key_change_mandelbrot(t_mlx *mlx, int key_code);

/*
**	image
*/

void		clear_image(t_mlx *mlx);
void		image_put_pixel(t_image *img, t_point point, int color);

/*
**	complex math
*/


t_complex		complex_add(t_complex a, t_complex b);
t_complex		complex_sqr(t_complex a);
double			complex_sqrt(t_complex a);

/*
**	mandelbrot
*/

void		mandelbrot(t_mlx *mlx);
void		calc_mandelbrot(t_point curr, t_mlx *mlx);
void		set_def_mand_params(t_mlx *mlx);
void		set_mandel_params(t_mlx *mlx);
int 		get_color(int iters, t_mlx *mlx);

/*
**	debug
*/

void		print_mandel_params(t_mlx *mlx);
void		print_params(t_mlx *mlx);

/*
**	jumps
*/

void		jump_to_left(t_mlx *mlx);
void		jump_mandel(t_mlx *mlx);
void		jump_star(t_mlx *mlx);
void		jump_maelstorm(t_mlx *mlx);

/*
**	julia
*/

void		set_def_julia_params(t_mlx *mlx);
void		julia(t_mlx *mlx);

/*
**	julia hooks
*/

void		mouse_change_julia(t_mlx *mlx, t_point pos);
void		key_change_julia(t_mlx *mlx, int keycode);

#endif
