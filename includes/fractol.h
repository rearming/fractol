/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:56:23 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/27 17:05:52 by sleonard         ###   ########.fr       */
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



/*
**	init
*/

t_mlx		*ft_mlx_init(void);

/*
**	error
*/

void		raise_error(int code);
void		show_usage(void);

/*
**	hook
*/

int 		cross_hook(void *param);
int 		key_hook(int key_code, void *param);

/*
**	image
*/

void		clear_image(t_mlx *mlx);
void		image_put_pixel(t_image *img, t_point point, int color);

/*
**	mandelbrot
*/

void		mandelbrot(t_mlx *mlx);
void		calc_mandelbrot(t_point curr, t_mlx *mlx);
void		set_def_mand_params(t_mlx *mlx);
void		set_mandel_params(t_mlx *mlx);

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
#endif
