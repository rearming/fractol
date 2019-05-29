/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 18:24:54 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/29 20:50:30 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

#include "fractol.h"

# define WIN_WIDTH 2550
# define WIN_HEIGHT 1300



#define CPU_RENDER 4000
#define GPU_RENDER 5000

#define IN 0
#define OUT 1

#define MOUSE 2
#define KEYBOARD 3

/*
**	terminal commands
*/

#define RESET 1000
#define MANDELBROT 1001
#define JULIA 1002
#define TREE 1003
#define PREPARE 1004
#define LISTEN 1005
#define END_TERM 1006


#endif
