void		image_put_pixel(__global int *img, int x, int y, int color, __global int *params)
{
	int		height;
	int		width;
	int		bpp;

	height = params[0];
	width = params[1];
	bpp = params[4];
	if (x < width && y < height
		&& y >= 0 && x >= 0)
		img[(x + y * width)] = color;
}

__kernel void		test(__global int *params, __global double *d_params,
		__global int *rand_params, __global int *img)
{
	int		x;
	int		y;
	int		height;
	int		width;
	int		bpp;

	height = params[0];
	width = params[1];
	bpp = params[4];
	printf("cl params[0]: [%d]\n", params[0]);
	printf("cl params[1]: [%d]\n", params[1]);
	printf("cl params[2]: [%d]\n", params[2]);
	printf("cl params[3]: [%d]\n", params[3]);

	printf("xside: [%f]\n", d_params[0]);
	printf("top: [%f]\n", d_params[1]);
	printf("left: [%f]\n", d_params[2]);

	printf("rand[0]: [%i]\n", rand_params[0]);
	printf("rand[1]: [%i]\n", rand_params[1]);
	printf("rand[2]: [%i]\n", rand_params[2]);

	printf("\n");
	x = 0;
	y = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			image_put_pixel(img, x, y, 0x000000FF, params);
			y++;
		}
		x++;
	}
}