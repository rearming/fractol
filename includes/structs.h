/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:54:14 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/13 11:19:47 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_image
{
	void		*img;
	char 		*data;
	int 		bpp;
	int 		line_size;
	int 		endian;
}				t_image;

typedef struct 	s_point
{
	int 		x;
	int 		y;
	int 		z;
	int 		color;
}				t_point;

typedef struct	s_params
{
	t_point		start;
	t_point		delta;
	double 		angle_X;
	double 		angle_Y;
	double 		angle_Z;
	char 		mode;
	int 		col_bot;
	int 		col_mid;
	int 		col_top;
}				t_params;

typedef struct 	s_map
{
	t_point		last_p;
	int 		scale;
	t_point 	**map;
	t_point		**b_map;
	t_point		midpoint;
	t_point		scaled_midpoint;
	char 		is_colored;
}				t_map;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_image		*img;
}				t_mlx;

#endif