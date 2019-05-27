/*void				image_put_pixel(t_point point, int color)
{
	if (!img)
		return ;
	if (!img->data)
		return ;
	if (point.x < WIN_WIDTH && point.y < WIN_HEIGHT
		&& point.y >= 0 && point.x >= 0)
		*(int *)(img->data +
				 ((point.x + point.y * WIN_WIDTH) * img->bpp)) = color;
}

int 				get_color(int iters, t_mlx *mlx)
{
	int red;
	int green;
	int blue;

	if (iters == mlx->max_iters)
		return (0x000000);
	red = iters % mlx->rand[0] * 64;
	green = iters % mlx->rand[1] * 32;
	blue = iters % mlx->rand[2] * 16;

	return (red << 16 | green << 8 | blue);
}*/

/*
__kernel void		calc_mandelbrot(__global)
{
	long double		temp;
	long double		zx;
	long double		zy;
	long double		cx;
	long double		cy;
	int 			iters;
	t_point			res;

	res = (t_point){curr.x, curr.y, 0, 1};
	cx = curr.x * mlx->mp.xscale + mlx->mp.left;
	cy = curr.y * mlx->mp.yscale + mlx->mp.top;
	zx = 0;
	zy = 0;
	iters = 0;
	while (zx * zx + zy * zy < 4 && iters < mlx->max_iters)
	{
		temp = zx * zx - zy * zy + cx;
		zy = 2 * zx * zy + cy;
		zx = temp;
		iters++;
	}
	res.color = get_color(iters, mlx);
	image_put_pixel(mlx->img, res, res.color);
}*/