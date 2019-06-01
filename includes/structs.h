/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:54:14 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/31 17:31:47 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct			s_complex
{
	double				x;
	double				y;
}						t_complex;

typedef struct			s_image
{
	void				*img;
	char				*data;
	int					bpp;
	int					line_size;
	int					endian;
}						t_image;

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_point;

typedef struct			s_line
{
	t_point				start;
	t_point				end;
	t_point				point;
	t_point				delta;
	int					steep;
	int					error;
	int					ystep;
}						t_line;

typedef struct			s_mp
{
	double				vert_shift;
	double				hor_shift;
	double				xside;
	double				yside;
	double				xscale;
	double				yscale;
	double				scale_x;
	double				scale_y;
	double				x_zoom;
	double				y_zoom;
	int					max_iters;
}						t_mp;

typedef struct			s_jul
{
	t_complex			c_part;
	double				radius;
	double				scale;
	double				scale_x;
	double				scale_y;
	int					max_iters;
	int					is_frozen;
	int					vert_shift;
	int					hor_shift;
	double				x_zoom;
	double				y_zoom;
}						t_jul;

typedef struct			s_tria
{
	int					side;
	int					r_calls;
	int					color;
	t_point				pos_top;
}						t_tria;

typedef struct			s_command
{
	int					status;
	int					action;
	int					frac_type;
	int					jump_area;
}						t_command;

typedef struct			s_erm
{
	char				buff[100];
	char				prev_cmd[10][100];
	int					i;
	int					cmd_i;
	t_command			cmd;
}						t_erm;

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
	cl_mem				double_params;
	cl_mem				rand_param;
}						t_cl;

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	t_image				*img;
	int					frac_type;
	int					rand[6];
	t_mp				mp;
	t_jul				jul;
	t_tria				tria;
	t_cl				cl;
	t_erm				term;
	int					rend_device;
}						t_mlx;

# define CL_BUFF_SIZE 10000

typedef struct			s_gnl_fdf
{
	char				*temp_str;
	char				*backup;
	char				buf[CL_BUFF_SIZE + 1];
	int					read_res;
	size_t				sum_len;
}						t_gnl_fdf;

#endif
