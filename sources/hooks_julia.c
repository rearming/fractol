/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:44:12 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/28 16:54:54 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mouse_change_julia(t_mlx *mlx, t_point pos)
{
	mlx->jul.c_part.x = (double) pos.x / WIN_WIDTH;
	mlx->jul.c_part.y = (double) pos.y / WIN_HEIGHT;
	julia_render(mlx);
}

void		key_change_julia(t_mlx *mlx, int keycode)
{
	if (keycode == SPACE)
		mlx->jul.is_frozen = mlx->jul.is_frozen == TRUE ? FALSE : TRUE;
}
