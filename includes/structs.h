/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:54:14 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/27 16:27:09 by sleonard         ###   ########.fr       */
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
	long double			xside;
	long double			kostil;
	long double			top;
	long double			yside;
	long double			xscale;
	long double			yscale;
	long double			left;
}						t_mp;

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	t_image				*img;
	int 				mode;
	t_mp				mp;
	int					max_iters;
	int 				rand[3];
}						t_mlx;

#endif