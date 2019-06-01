/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 18:12:10 by sleonard          #+#    #+#             */
/*   Updated: 2019/06/01 20:56:40 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		cl_fill_julia_buffer(t_mlx *mlx)
{
	int			params[10];
	double		d_params[10];

	params[0] = WIN_HEIGHT;
	params[1] = WIN_WIDTH;
	params[2] = mlx->jul.max_iters;
	d_params[0] = mlx->jul.c_part.x;
	d_params[1] = mlx->jul.c_part.y;
	d_params[2] = mlx->jul.radius;
	d_params[3] = mlx->jul.vert_shift;
	d_params[4] = mlx->jul.hor_shift;
	d_params[5] = mlx->jul.scale;
	d_params[6] = mlx->jul.scale_x;
	d_params[7] = mlx->jul.scale_y;

	clEnqueueWriteBuffer(mlx->cl.queue, mlx->cl.params, CL_TRUE, 0,
						sizeof(int) * 10, &params, 0, NULL, NULL);
	clEnqueueWriteBuffer(mlx->cl.queue, mlx->cl.double_params, CL_TRUE, 0,
						sizeof(double) * 10, &d_params, 0, NULL, NULL);
	clEnqueueWriteBuffer(mlx->cl.queue, mlx->cl.rand_param, CL_TRUE, 0,
						sizeof(int) * 6, &mlx->rand, 0, NULL, NULL);
}

void		cl_fill_mandelbrot_buffer(t_mlx *mlx)
{
	int		params[10];

	params[0] = WIN_HEIGHT;
	params[1] = WIN_WIDTH;
	params[2] = mlx->mp.max_iters;

	//printf("cl->queue: [%p]\n", mlx->cl.queue); //todo fix segfault after cleanup
	clEnqueueWriteBuffer(mlx->cl.queue, mlx->cl.params, CL_TRUE, 0,
						sizeof(int) * 10, &params, 0, NULL, NULL);
	clEnqueueWriteBuffer(mlx->cl.queue, mlx->cl.double_params, CL_TRUE, 0,
						sizeof(double) * 10, &mlx->mp, 0, NULL, NULL);
	clEnqueueWriteBuffer(mlx->cl.queue, mlx->cl.rand_param, CL_TRUE, 0,
						sizeof(int) * 6, &mlx->rand, 0, NULL, NULL);
}

void		julia_render(t_mlx *mlx)
{
	int		ret;

	if (mlx->rend_device == GPU_RENDER)
	{
		cl_fill_julia_buffer(mlx);
		cl_run_kernels(mlx);
		ret = clEnqueueReadBuffer(mlx->cl.queue, mlx->cl.mem_img, CL_TRUE, 0,
								sizeof(int) * WIN_WIDTH * WIN_HEIGHT,
									mlx->img->data, 0, NULL, NULL);
		if (ret)
			raise_error(ERR_OPENCL);
	}
	if (mlx->rend_device == CPU_RENDER)
		julia(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	screen_info(mlx);
}

void		mandelbrot_render(t_mlx *mlx)
{
	int		ret;

	mlx->mp.xscale = (mlx->mp.xside / WIN_WIDTH);
	mlx->mp.yscale = (mlx->mp.yside / WIN_HEIGHT);
	if (mlx->rend_device == GPU_RENDER)
	{
		cl_fill_mandelbrot_buffer(mlx);
		cl_run_kernels(mlx);
		ret = clEnqueueReadBuffer(mlx->cl.queue, mlx->cl.mem_img, CL_TRUE, 0,
								sizeof(int) * WIN_WIDTH * WIN_HEIGHT,
									mlx->img->data, 0, NULL, NULL);
		if (ret)
			raise_error(ERR_OPENCL);
	}
	if (mlx->rend_device == CPU_RENDER)
		mandelbrot(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	screen_info(mlx);
}
