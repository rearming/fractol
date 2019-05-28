/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 17:10:01 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/28 19:31:15 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		cl_set_kernel(t_cl *cl)
{
	int 	ret;

	ret = 0;
	cl->params = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, sizeof(int) * 10, NULL, &ret);
	cl->double_params = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, sizeof(double) * 10, NULL, &ret);
	cl->rand_param = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, sizeof(int) * 3, NULL, &ret);
	cl->mem_img = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, sizeof(int) * WIN_WIDTH * WIN_HEIGHT, NULL, &ret);

	ret += clSetKernelArg(cl->kernel, 0, sizeof(cl_mem), &cl->params);
	ret += clSetKernelArg(cl->kernel, 1, sizeof(cl_mem), &cl->double_params);
	ret += clSetKernelArg(cl->kernel, 2, sizeof(cl_mem), &cl->rand_param);
	ret += clSetKernelArg(cl->kernel, 3, sizeof(cl_mem), &cl->mem_img);
	if (ret)
		raise_error(ERR_OPENCL);
}

t_cl		cl_init(t_mlx *mlx)
{
	t_cl		cl;
	int			ret;
	char 		*cl_file;
	size_t		size;

	if ((ret = clGetPlatformIDs(1, &cl.platform_id, &cl.ret_num_platforms)))
		raise_error(ERR_OPENCL);
	if ((ret = clGetDeviceIDs(cl.platform_id, CL_DEVICE_TYPE_GPU, 1, &cl.device_id, &cl.ret_num_devices)))
		raise_error(ERR_OPENCL);
	cl.context = clCreateContext(NULL, 1, &cl.device_id, NULL, NULL, &ret);
	cl.queue = clCreateCommandQueue(cl.context, cl.device_id, 0, &ret);

	if (mlx->mode == MANDELBROT)
		cl_file = cl_gnl(open("/Users/sleonard/7_day/fractol/sources/gpu_mandelbrot.cl", O_RDONLY));
	if (mlx->mode == JULIA)
		cl_file = cl_gnl(open("/Users/sleonard/7_day/fractol/sources/gpu_julia.cl", O_RDONLY));
	size = ft_strlen(cl_file);
	cl.program = clCreateProgramWithSource(cl.context, 1, (const char **)&cl_file, &size, &ret);

	ret = clBuildProgram(cl.program, 1, &cl.device_id, NULL, NULL, NULL);
	if (mlx->mode == MANDELBROT)
		cl.kernel = clCreateKernel(cl.program, "mandelbrot", &ret);
	if (mlx->mode == JULIA)
		cl.kernel = clCreateKernel(cl.program, "julia", &ret);
	cl_set_kernel(&cl);
	if (ret)
		raise_error(ERR_OPENCL);
	free(cl_file);
	return (cl);
}

void		cl_fill_julia_buffer(t_mlx *mlx)
{
	int 		params[10];
	double 		d_params[10];

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
						 sizeof(int) * 3, &mlx->rand, 0, NULL, NULL);
}

void		cl_fill_mandelbrot_buffer(t_mlx *mlx)
{
	int 	params[10];

	params[0] = WIN_HEIGHT;
	params[1] = WIN_WIDTH;
	params[2] = mlx->mp.max_iters;

	clEnqueueWriteBuffer(mlx->cl.queue, mlx->cl.params, CL_TRUE, 0,
			sizeof(int) * 10, &params, 0, NULL, NULL);
	clEnqueueWriteBuffer(mlx->cl.queue, mlx->cl.double_params, CL_TRUE, 0,
						 sizeof(double) * 10, &mlx->mp, 0, NULL, NULL);
	clEnqueueWriteBuffer(mlx->cl.queue, mlx->cl.rand_param, CL_TRUE, 0,
			sizeof(int) * 3, &mlx->rand, 0, NULL, NULL);
}

void		cl_run_kernels(t_mlx *mlx)
{
	size_t 	kern_num;
	int		ret;

	kern_num = WIN_HEIGHT * WIN_WIDTH;
	ret = clEnqueueNDRangeKernel(mlx->cl.queue, mlx->cl.kernel, 1,
			NULL, &kern_num, NULL, 0, NULL, NULL);
	if (ret)
		raise_error(ERR_OPENCL);
}

void		julia_render(t_mlx *mlx)
{
	int 	ret;

	if (mlx->render_mode == GPU_RENDER)
	{
		cl_fill_julia_buffer(mlx);
		cl_run_kernels(mlx);
		ret = clEnqueueReadBuffer(mlx->cl.queue, mlx->cl.mem_img, CL_TRUE, 0,
								  sizeof(int) * WIN_WIDTH * WIN_HEIGHT, mlx->img->data, 0, NULL, NULL);
		if (ret)
			raise_error(ERR_OPENCL);
	}
	if (mlx->render_mode == CPU_RENDER)
		julia(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}

void		mandelbrot_render(t_mlx *mlx)
{
	int 	ret;

	if (mlx->render_mode == GPU_RENDER)
	{
		cl_fill_mandelbrot_buffer(mlx);
		cl_run_kernels(mlx);
		ret = clEnqueueReadBuffer(mlx->cl.queue, mlx->cl.mem_img, CL_TRUE, 0,
								  sizeof(int) * WIN_WIDTH * WIN_HEIGHT, mlx->img->data, 0, NULL, NULL);
		if (ret)
			raise_error(ERR_OPENCL);
	}
	if (mlx->render_mode == CPU_RENDER)
		mandelbrot(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}
