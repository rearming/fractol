/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:56:23 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/24 18:28:06 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <math.h>
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>

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

#endif
