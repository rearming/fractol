/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:54:14 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/28 11:50:56 by sleonard         ###   ########.fr       */
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
	double			top;
	double			left;
	double			xside;
	double			yside;
	double			xscale;
	double			yscale;
	double 			scale_x;
	double 			scale_y;

}						t_mp;

typedef struct			s_cl
{
	cl_context			context;
	cl_command_queue	queue;
	cl_platform_id		platform_id;
	cl_uint				ret_num_platforms;
	cl_uint				ret_num_devices;
	cl_device_id		device_id;
	cl_program			program;
	cl_kernel			kernel;

	cl_mem				mem_img;
	cl_mem				params;
	cl_mem 				double_params;
	cl_mem 				rand_param;
}						t_cl;

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	t_image				*img;
	int 				mode;
	int					max_iters;
	int 				rand[3];
	t_mp				mp;
	t_cl				cl;
	int 				render_mode;
}						t_mlx;

#define CL_BUFF_SIZE 10000

typedef struct	s_gnl_fdf
{
	char		*temp_str;
	char		*backup;
	char		buf[CL_BUFF_SIZE + 1];
	int			read_res;
	size_t		sum_len;
	char		*result;
}				t_gnl_fdf;

#endif