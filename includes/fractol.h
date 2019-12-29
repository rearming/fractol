/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:56:23 by sleonard          #+#    #+#             */
/*   Updated: 2019/12/26 18:19:16 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

# include "libft.h"
# include "structs.h"
# include "colors.h"
# include "key_codes.h"
# include "errors.h"
# include "defines.h"

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

void		cl_init(t_mlx *mlx);
char		*cl_gnl(int fd);
void		cl_new_program(t_mlx *mlx);

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
**	Open CL clean
*/

void		clean_opencl(t_mlx *mlx);
void		exit_clean(t_mlx *mlx);
/*
**	error
*/

void		raise_error(int code);
void		show_usage(void);

/*
**	hooks utils
*/

int			cross_hook(void *param);
int			key_hook(int key_code, void *param);
int			mouse_move(int x, int y, void *param);
int mouse_action(int button_code, int y, int x, void *param);

/*
**	terminal parsing
*/

void		parse_term_input(t_mlx *mlx, int key);
char		get_char(int key);

/*
**	terminal string utils
*/

void		clear_command_data(t_mlx *mlx);
void		update_backup(t_mlx *mlx);
void		check_backup(t_mlx *mlx, int key);
void		del_char(t_mlx *mlx);

/*
**	terminal command processing
*/

void		command_based_render(t_mlx *mlx);
void		change_max_iters(t_mlx *mlx);
void		process_colors(t_mlx *mlx);
void		process_jump(t_mlx *mlx);
void		process_command(t_mlx *mlx);

/*
**	fuck norme
*/
void		get_fractal_type(t_mlx *mlx);

/*
**	image
*/

void		clear_image(t_mlx *mlx);
void		image_put_pixel(t_image *img, t_point point, int color);

/*
**	bresenham line
*/

void		bresen_line(t_mlx *mlx, t_point start, t_point end);

/*
**	complex math
*/

t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_sqr(t_complex a);
double		complex_sqrt(t_complex a);

/*
**	mandelbrot
*/

void		mandelbrot(t_mlx *mlx);
void		calc_mandelbrot(t_point curr, t_mlx *mlx);
void		set_def_mand_params(t_mlx *mlx);
int			get_color(int iters, t_mlx *mlx);

/*
**	hooks mandlelbrot
*/

void		key_change_mandelbrot(t_mlx *mlx, int key_code);
void		mouse_change_mandelbort(t_point pos, t_mlx *mlx);
void		mouse_action_mandelbrot(t_mlx *mlx, int button_code);
void		zoom_mandelbrot(t_mlx *mlx, int mode);

/*
**	debug
*/

void		print_mandel_params(t_mlx *mlx);
void		print_params(t_mlx *mlx);

/*
**	jumps
*/

void		jump_home(t_mlx *mlx);
void		jump_deep_self(t_mlx *mlx);
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
void		mouse_action_julia(t_mlx *mlx, int button_code);

/*
**	triangle
*/

void		set_def_triangle_params(t_mlx *mlx);
void		triangle(t_mlx *mlx);
void		r_triangle(t_mlx *mlx, t_point top, int len, int r_calls);

/*
**	hooks triangle
*/

void		key_change_tria(t_mlx *mlx, int key_code);

/*
**	rotation
*/

void		rotate_z(t_point *point, t_point center, double angle);

/*
**	screen info
*/

void		screen_info(t_mlx *mlx);
void		terminal_info(t_mlx *mlx);

#endif
