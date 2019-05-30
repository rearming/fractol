/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:32:05 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/24 14:50:39 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		clear_image(t_mlx *mlx)
{
	if (!mlx->img->img || !mlx->img->data)
		return ;
	ft_bzero(mlx->img->data, WIN_HEIGHT * WIN_WIDTH * mlx->img->bpp);
}

void		image_put_pixel(t_image *img, t_point point, int color)
{
	if (!img)
		return ;
	if (!img->data)
		return ;
	if (point.x < WIN_WIDTH && point.y < WIN_HEIGHT
						&& point.y >= 0 && point.x >= 0)
		*((int*)(img->data +
			((point.x + point.y * WIN_WIDTH) * img->bpp))) = color;
}
