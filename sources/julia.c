/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:22:01 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/29 17:11:34 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "structs.h"

void			set_def_julia_params(t_mlx *mlx)
{
	mlx->mode = JULIA;
	mlx->render_mode = GPU_RENDER;

	mlx->rand[0] = 4;
	mlx->rand[1] = 8;
	mlx->rand[2] = 16;
	mlx->jul.scale_x = (double)WIN_WIDTH / WIN_HEIGHT;
	mlx->jul.scale_y = (double)WIN_HEIGHT / WIN_WIDTH;
	mlx->jul.radius = 2;
	mlx->jul.max_iters = 200;
	mlx->jul.hor_shift = 1;
	mlx->jul.vert_shift = 500;
	mlx->jul.scale = 0.7;
	mlx->jul.c_part.x = 0.2;
	mlx->jul.c_part.y = 0.7;
	mlx->jul.x_zoom = 1;
	mlx->jul.y_zoom = 1;
}

t_complex		map_point(t_point curr, double radius)
{
	t_complex		c;
	int 			coeff;

	coeff = WIN_WIDTH < WIN_HEIGHT ? WIN_WIDTH : WIN_HEIGHT;
	c.x = 2 * radius * (curr.x - WIN_WIDTH / 2.0) / coeff;
	c.y = 2 * radius * (curr.y - WIN_HEIGHT / 2.0) / coeff;
	return (c);
}

void			calc_julia(t_point curr, t_mlx *mlx)
{
	t_complex		z0;
	t_complex		z1;
	int 			iters;

	iters = 0;
	z0 = map_point(curr, mlx->jul.radius);
	while (iters <= mlx->jul.max_iters)
	{
		z1 = complex_add(complex_sqr(z0), mlx->jul.c_part);
		if (z1.x * z1.x + z1.y * z1.y > mlx->jul.radius * mlx->jul.radius)
		{
			image_put_pixel(mlx->img, (t_point){curr.x, curr.y, 0}, get_color(iters, mlx));
			break ;
		}
		z0 = z1;
		iters++;
	}
	if (iters > mlx->jul.max_iters)
		image_put_pixel(mlx->img, (t_point){curr.x, curr.y, 0}, BLACK);
}

void			julia(t_mlx *mlx)
{
	t_point		curr;

	curr = (t_point){0, 0, 0, 0};
	curr.x = 0;
	while (curr.x < WIN_WIDTH)
	{
		curr.y = 0;
		while (curr.y < WIN_HEIGHT)
		{
			calc_julia(curr, mlx);
			curr.y++;
		}
		curr.x++;
	}
}
