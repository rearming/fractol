/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpu_mandelbrot.cl                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:56:42 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/28 16:56:42 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_point
{
	int 		x;
	int 		y;
}				t_point;

void		image_put_pixel(__global int *img, size_t pos,
							int color, int width, int height)
{
	size_t		limit;

	limit = width * height;
	if (pos >= 0 && pos <= limit)
		img[pos] = color;
}

double				d_abs(double n)
{
	return (n < 0 ? n * -1 : n);
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

__kernel void		mandelbrot(__global int *params, __global double *d_params,
		__global int *rand_params, __global int *img)
{
	double			temp;
	double			zx;
	double			zy;
	double			cx;
	double			cy;
	int 			iters;

	int				color;
	int				height;
	int				width;
	int				max_iters;
	int 			is_burning;
	size_t			g_id;

	t_point			curr;
	double			top;
	double			left;
	double			xscale;
	double			yscale;

	g_id = get_global_id(0);

	height = params[0];
	width = params[1];
	max_iters = params[2];
	is_burning = params[3];

	curr.x = g_id % width;
	curr.y = g_id / height;

	top = d_params[0];
	left = d_params[1];
	xscale = d_params[4];
	yscale = d_params[5];

	if (is_burning)
		top -= 0.5;
	cx = curr.x * xscale + left;
	cy = curr.y * yscale + top;
	zx = 0;
	zy = 0;
	iters = 0;
	while (zx * zx + zy * zy < 4 && iters < max_iters)
	{
		temp = zx * zx - zy * zy + cx;
		zy = 2 * zx * zy + cy;
		zx = temp;
		if (is_burning)
		{
			zy = d_abs(zy);
			zx = d_abs(zx);
		}
		iters++;
	}
	color = get_color(iters, max_iters, rand_params);
	image_put_pixel(img, g_id, color, width, height);
}