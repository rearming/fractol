/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:56:11 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/24 17:10:24 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int 	main(void)
{
	t_mlx		*mlx;

	mlx = ft_mlx_init();
	mandelbrot(mlx);
	mlx_hook(mlx->win, 2, 0, &key_hook, mlx);
	mlx_hook(mlx->win, 17, 0, &cross_hook, mlx);
	mlx_loop(mlx);
	return (0);
}