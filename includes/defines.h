/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 18:24:54 by sleonard          #+#    #+#             */
/*   Updated: 2019/06/03 16:20:04 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include "fractol.h"

# ifdef __APPLE__
#  define WIN_WIDTH 2550
#  define WIN_HEIGHT 1300
# else
#  define WIN_WIDTH 1820
#  define WIN_HEIGHT 980
# endif

# define TRUE 1
# define FALSE 0

/*
**	render modes
*/

# define CPU_RENDER 4000
# define GPU_RENDER 5000

/*
**	zoom modes
*/

# define IN 0
# define OUT 1
# define MOUSE 2

/*
**	fractal types
*/

# define MANDELBROT 1001
# define JULIA 1002
# define TREE 1003
# define TRIA 1004
# define BURNING 1005

/*
**	terminal commands
*/

# define RESET 1000
# define PREPARE 1004
# define LISTEN 1005
# define RENDER 1010
# define SET 1012
# define JUMP 1013
# define HELP 1014

/*
**	jump areas
*/

# define DEEP_SELF 1014
# define STAR_PIXEL 1015
# define MAELSTORM 1016
# define HOME 1017

#endif
