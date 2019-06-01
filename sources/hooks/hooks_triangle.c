/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:28:12 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/31 20:01:53 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		key_change_tria(t_mlx *mlx, int key_code)
{
	clear_image(mlx);
	if (key_code == N)
		set_def_triangle_params(mlx);
	if (key_code == SPACE && mlx->tria.r_calls < 11)
		mlx->tria.r_calls++;
	triangle(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	screen_info(mlx);
}
