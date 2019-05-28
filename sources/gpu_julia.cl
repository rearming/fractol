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
	red = iters % rand_params[0] * 64;
	green = iters % rand_params[1] * 32;
	blue = iters % rand_params[2] * 16;

	return (red << 16 | green << 8 | blue);
}

double			complex_mod(double x, double y)
{
	return sqrt(x * x + y * y);
}

t_complex		complex_add(t_complex a, t_complex b)
{
	t_complex c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

t_complex		complex_sqr(t_complex a)
{
	t_complex c;

	c.x = a.x * a.x - a.y * a.y;
	c.y = 2 * a.x * a.y;
	return c;
}

double			complex_sqrt(t_complex a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}

t_complex		map_point(t_point curr, double radius, int width, int height)
{
	t_complex		c;
	double			scale_x;
	double			scale_y;

	scale_x = (double)width / height;
	scale_y = (double)height / width;
	c.x = 2 * radius * (curr.x - width / 2.0) / width;
	c.y = 2 * radius * (curr.y - height / 2.0) / height;
	c.x *= scale_x;
	c.y *= scale_y;
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
	t_complex		c_part;

	g_id = get_global_id(0);

	height = params[0];
	width = params[1];
	max_iters = params[2];

	x = g_id % width;
	y = g_id / height - 500;

	c_part.x = d_params[0];
	c_part.y = d_params[1];
	radius = d_params[2];

	iters = 0;
	z0 = map_point((t_point){x, y, 0}, radius, width, height);
	while (iters <= max_iters)
	{
		z1 = complex_add(complex_sqr(z0), c_part);
		if (complex_sqrt(z1) > radius)
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