/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpu_julia.cl                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:56:46 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/28 16:56:46 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma OPENCL EXTENSION cl_khr_byte_addressable_store : enable
#pragma OPENCL EXTENSION cl_khr_fp64 : enable

typedef struct	s_complex
{
	double 		x;
	double 		y;
}				t_complex;

typedef struct	s_point
{
	int 	x;
	int 	y;
}				t_point;

void		image_put_pixel(__global int *img, size_t pos,
							int color, int width, int height)
{
	size_t		limit;

	limit = width * height;
	if (pos >= 0 && pos <= limit)
		img[pos] = color;
}

int 				get_color(int iters, int max_iters, __global int *rand_params)
{
	int				red;
	int				green;
	int				blue;

	if (iters == max_iters)
		return (0x000000);
	red = iters % rand_params[0] * rand_params[3];
	green = iters % rand_params[1] * rand_params[4];
	blue = iters % rand_params[2] * rand_params[5];

	return (red << 16 | green << 8 | blue);
}

t_complex		complex_add(t_complex a, t_complex b)
{
	t_complex c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

double				d_abs(double n)
{
	return (n < 0 ? n * -1 : n);
}

t_complex		complex_sqr(t_complex a)
{
	t_complex c;

	c.x = a.x * a.x - a.y * a.y;
	c.y = 2 * a.x * a.y;
	return c;
}

t_complex		map_point(t_point curr, double radius, int width, int height,
							double scale, double scale_x, double scale_y)
{
	t_complex		c;

	c.x = radius * (curr.x - width / 2.0) / width;
	c.y =  radius * (curr.y - height / 2.0) / height;
	c.x *= scale_x * scale;
	c.y *= scale_y * scale;
	return (c);
}

__kernel void			julia(__global int *params, __global double *d_params,
		__global int *rand_params, __global int *img)
{
	t_complex		z0;
	t_complex		z1;
	int 			iters;

	int 			x;
	int 			y;

	size_t			g_id;
	int 			height;
	int 			width;
	int 			max_iters;

	double			radius;
	double			vert_shift;
	double			hor_shift;
	double			scale;
	double 			scale_x;
	double 			scale_y;
	t_complex		c_part;

	g_id = get_global_id(0);

	height = params[0];
	width = params[1];
	max_iters = params[2];

	c_part.x = d_params[0];
	c_part.y = d_params[1];
	radius = d_params[2];
	vert_shift = d_params[3];
	hor_shift = d_params[4];
	scale = d_params[5];
	scale_x = d_params[6];
	scale_y = d_params[7];

	x = g_id % width - hor_shift / (scale);
	y = g_id / height - vert_shift / (scale * 2);

	iters = 0;
	z0 = map_point((t_point){x, y, 0}, radius, width, height, scale, scale_x, scale_y);
	while (iters <= max_iters)
	{
		z1 = complex_add(complex_sqr(z0), c_part);
		if (z1.x * z1.x + z1.y * z1.y > radius * radius)
		{
			image_put_pixel(img, g_id, get_color(iters, max_iters, rand_params), width, height);
			break ;
		}
		z0 = z1;
		iters++;
	}
	if (iters > max_iters)
		image_put_pixel(img, g_id, 0x000000, width, height);
}