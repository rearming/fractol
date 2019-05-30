/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 17:10:01 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/30 18:14:50 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		cl_set_kernel(t_cl *cl)
{
	int		ret;

	ret = 0;
	cl->params = clCreateBuffer(cl->context, CL_MEM_READ_WRITE,
			sizeof(int) * 10, NULL, &ret);
	cl->double_params = clCreateBuffer(cl->context, CL_MEM_READ_WRITE,
			sizeof(double) * 10, NULL, &ret);
	cl->rand_param = clCreateBuffer(cl->context, CL_MEM_READ_WRITE,
			sizeof(int) * 6, NULL, &ret);
	cl->mem_img = clCreateBuffer(cl->context, CL_MEM_READ_WRITE,
			sizeof(int) * WIN_WIDTH * WIN_HEIGHT, NULL, &ret);
	ret += clSetKernelArg(cl->kernel, 0, sizeof(cl_mem), &cl->params);
	ret += clSetKernelArg(cl->kernel, 1, sizeof(cl_mem), &cl->double_params);
	ret += clSetKernelArg(cl->kernel, 2, sizeof(cl_mem), &cl->rand_param);
	ret += clSetKernelArg(cl->kernel, 3, sizeof(cl_mem), &cl->mem_img);
	if (ret)
		raise_error(ERR_OPENCL);
}

char		*get_cl_file(t_mlx *mlx, size_t *size)
{
	char	*cl_file;

	if (mlx->frac_type == MANDELBROT)
		cl_file = cl_gnl(open("./sources/open_cl/gpu_mandelbrot.cl", O_RDONLY));
	if (mlx->frac_type == JULIA)
		cl_file = cl_gnl(open("./sources/open_cl/gpu_julia.cl", O_RDONLY));
	*size = ft_strlen(cl_file);
	return (cl_file);
}

t_cl		cl_init(t_mlx *mlx)
{
	t_cl		cl;
	int			ret;
	char		*cl_file;
	size_t		size;

	if ((ret = clGetPlatformIDs(1, &cl.platform_id, &cl.ret_num_platforms)))
		raise_error(ERR_OPENCL);
	if ((ret = clGetDeviceIDs(cl.platform_id, CL_DEVICE_TYPE_GPU, 1,
			&cl.device_id, &cl.ret_num_devices)))
		raise_error(ERR_OPENCL);
	cl.context = clCreateContext(NULL, 1, &cl.device_id, NULL, NULL, &ret);
	cl.queue = clCreateCommandQueue(cl.context, cl.device_id, 0, &ret);
	cl_file = get_cl_file(mlx, &size);
	cl.program = clCreateProgramWithSource(cl.context, 1,
			(const char **)&cl_file, &size, &ret);
	if ((ret = clBuildProgram(cl.program, 1, &cl.device_id, NULL, NULL, NULL)))
		raise_error(ERR_OPENCL);
	if (mlx->frac_type == MANDELBROT)
		cl.kernel = clCreateKernel(cl.program, "mandelbrot", &ret);
	if (mlx->frac_type == JULIA)
		cl.kernel = clCreateKernel(cl.program, "julia", &ret);
	cl_set_kernel(&cl);
	free(cl_file);
	return (cl);
}

void		cl_run_kernels(t_mlx *mlx)
{
	size_t	kern_num;
	int		ret;

	printf("wtf??\n");
	kern_num = WIN_HEIGHT * WIN_WIDTH;
	ret = clEnqueueNDRangeKernel(mlx->cl.queue, mlx->cl.kernel, 1,
			NULL, &kern_num, NULL, 0, NULL, NULL);
	if (ret)
		raise_error(ERR_OPENCL);
}
