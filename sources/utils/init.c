/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:18:44 by sleonard          #+#    #+#             */
/*   Updated: 2019/06/03 09:46:53 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx		*ft_mlx_init(void)
{
	t_mlx		*mlx;

	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		raise_error(ERR_MALLOC);
	if (!(mlx->img = (t_image*)malloc(sizeof(t_image))))
		raise_error(ERR_MALLOC);
	if (!(mlx->mlx = mlx_init()))
		raise_error(ERR_MLX_INIT);
	if (!(mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Dota 2")))
		raise_error(ERR_MLX_WIN);
	if (!(mlx->img->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT)))
		raise_error(ERR_MLX_IMG);
	if (!(mlx->img->data = mlx_get_data_addr(mlx->img->img,
			&mlx->img->bpp, &mlx->img->line_size, &mlx->img->endian)))
		raise_error(ERR_MLX_IMG_DATA);
	mlx->img->bpp /= 8;
	mlx->term = (t_erm){{0}, {{0}}, 0, 0, {0, 0, 0, 0}};
	mlx->is_first = TRUE;
	mlx->is_burn = FALSE;
	return (mlx);
}
