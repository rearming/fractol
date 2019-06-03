/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_opencl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 19:53:36 by sleonard          #+#    #+#             */
/*   Updated: 2019/06/03 10:27:17 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	clean_opencl2(t_mlx *mlx)
{
	int		ret;

	ret = 0;
	if (mlx->cl.mem_img)
		ret += clReleaseMemObject(mlx->cl.mem_img);
	if (mlx->cl.params)
		ret += clReleaseMemObject(mlx->cl.params);
	if (mlx->cl.double_params)
		ret += clReleaseMemObject(mlx->cl.double_params);
	if (mlx->cl.rand_param)
		ret += clReleaseMemObject(mlx->cl.rand_param);
	if (mlx->cl.context)
		ret += clReleaseContext(mlx->cl.context);
	if (ret)
		raise_error(ERR_OPENCL_CLEAN);
}

void		clean_opencl(t_mlx *mlx)
{
	int ret;

	ret = 0;
	if (mlx->is_first || mlx->frac_type == TRIA)
	{
		mlx->is_first = mlx->is_first ? FALSE : mlx->is_first;
		return ;
	}
	if (mlx->cl.queue)
	{
		ret += clFlush(mlx->cl.queue);
		ret += clFinish(mlx->cl.queue);
		ret += clReleaseCommandQueue(mlx->cl.queue);
	}
	if (mlx->cl.device_id)
		clReleaseDevice(mlx->cl.device_id);
	if (mlx->cl.kernel)
		ret += clReleaseKernel(mlx->cl.kernel);
	if (mlx->cl.program)
		ret += clReleaseProgram(mlx->cl.program);
	clean_opencl2(mlx);
	if (ret)
		raise_error(ERR_OPENCL_CLEAN);
}
