/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 17:10:01 by sleonard          #+#    #+#             */
/*   Updated: 2019/06/02 13:33:55 by rearming         ###   ########.fr       */
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

void		cl_init(t_mlx *mlx)
{
	int			ret;
	char		*cl_file;
	size_t		size;

	if ((ret = clGetPlatformIDs(1, &mlx->cl.platform_id, &mlx->cl.ret_num_platforms)))
		raise_error(ERR_OPENCL);
	if ((ret = clGetDeviceIDs(mlx->cl.platform_id, CL_DEVICE_TYPE_GPU, 1,
			&mlx->cl.device_id, &mlx->cl.ret_num_devices)))
		raise_error(ERR_OPENCL);
	mlx->cl.context = clCreateContext(NULL, 1, &mlx->cl.device_id, NULL, NULL, &ret);
	mlx->cl.queue = clCreateCommandQueue(mlx->cl.context, mlx->cl.device_id, 0, &ret);
	cl_file = get_cl_file(mlx, &size);
	mlx->cl.program = clCreateProgramWithSource(mlx->cl.context, 1,
												(const char **)&cl_file, &size, &ret);
	if (ret)
		raise_error(ERR_OPENCL);
	if ((ret = clBuildProgram(mlx->cl.program, 1, &mlx->cl.device_id, NULL, NULL, NULL)))
		raise_error(ERR_OPENCL);
	if (mlx->frac_type == MANDELBROT)
		mlx->cl.kernel = clCreateKernel(mlx->cl.program, "mandelbrot", &ret);
	if (mlx->frac_type == JULIA)
		mlx->cl.kernel = clCreateKernel(mlx->cl.program, "julia", &ret);
	if (ret)
		raise_error(ERR_OPENCL);
	cl_set_kernel(&mlx->cl);
	free(cl_file);
}

void		cl_run_kernels(t_mlx *mlx)
{
	size_t	kern_num;
	int		ret;

	kern_num = WIN_HEIGHT * WIN_WIDTH;
	ret = clEnqueueNDRangeKernel(mlx->cl.queue, mlx->cl.kernel, 1,
			NULL, &kern_num, NULL, 0, NULL, NULL);
	if (ret)
		raise_error(ERR_OPENCL);

}
