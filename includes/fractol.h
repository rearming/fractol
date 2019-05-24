/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:56:23 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/24 14:37:11 by sleonard         ###   ########.fr       */
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

/*
**	main functions
*/



/*
**	init functions
*/

t_mlx		*ft_mlx_init(void);

/*
**	error functions
*/

void		raise_error(int code);

/*
**	mandelbrot functions
*/

void	mandelbrot(t_mlx *mlx);

#endif
