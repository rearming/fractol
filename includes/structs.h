/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:54:14 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/27 11:29:46 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct			s_image
{
	void				*img;
	char 				*data;
	int 				bpp;
	int 				line_size;
	int 				endian;
}						t_image;

typedef struct 			s_point
{
	int 				x;
	int 				y;
	int 				z;
	int 				color;
}						t_point;

typedef struct			s_mp
{
	long double			left;
	long double			top;
	long double 		xside;
	long double 		yside;
	long double 		xscale;
	long double 		yscale;
	int 				max_iters;
}						t_mp;

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	t_image				*img;
	int 				mode;
	t_mp				mp;
}						t_mlx;

#endif