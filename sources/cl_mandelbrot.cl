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
	int4			rand;
	size_t			g_id;

	int				x;
	int				y;

	double			top;
	double			left;
	double			xside;
	double			yside;
	double			xscale;
	double			yscale;

	g_id = get_global_id(0);

	height = params[0];
	width = params[1];
	max_iters = params[2];

	x = g_id % width;
	y = g_id / height;

	top = d_params[0];
	left = d_params[1];
	xside = d_params[2];
	yside = d_params[3];
	xscale = d_params[4];
	yscale = d_params[5];

	cx = x * xscale + left;
	cy = y * yscale + top;	//todo y - 1?
	zx = 0;
	zy = 0;
	iters = 0;
	while (zx * zx + zy * zy < 4 && iters < max_iters)
	{
		temp = zx * zx - zy * zy + cx;
		zy = 2 * zx * zy + cy;
		zx = temp;
		iters++;
	}
	color = get_color(iters, max_iters, rand_params);
	image_put_pixel(img, g_id, color, width, height);
}