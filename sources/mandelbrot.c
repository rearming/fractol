/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:48:09 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/24 19:08:07 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_mandelbrot(t_point curr, t_mlx *mlx)
{
	double		temp;
	double		zr;
	double		zi;
	double		cr;
	double 		ci;
	int 		count;

	double left = -1.75;
	double top = -0.25;
	double xside = 0.25;
	double yside = 0.45;

	cr = curr.x * 0.5 + left;

	// c_imaginary
	ci = curr.y * 0.8 + top;

	// z_real
	zr = 0;

	// z_imaginary
	zi = 0;
	count = 0;

	// Calculate whether c(c_real + c_imaginary) belongs
	// to the Mandelbrot set or not and draw a pixel
	// at coordinates (x, y) accordingly
	// If you reach the Maximum number of iterations
	// and If the distance from the origin is
	// greater than 2 exit the loop
	while (zr * zr + zi * zi < 4 && count < MAX_ITERS)
	{
		// Calculate Mandelbrot function
		// z = z*z + c where z is a complex number

		// tempx = z_real*_real - z_imaginary*z_imaginary + c_real
		temp = zr * zr - zi * zi + cr;

		// 2*z_real*z_imaginary + c_imaginary
		zi = 2 * zr * zi + ci;

		// Updating z_real = tempx
		zr = temp;

		// Increment count
		count++;
	}
	image_put_pixel(mlx->img, (t_point){curr.x, curr.y, 0}, count);
}

void	mandelbrot(t_mlx *mlx)
{
	t_point		curr;


	curr.x = 0;
	while (curr.x <= WIN_WIDTH)
	{
		curr.y = 0;
		while (curr.y <= WIN_HEIGHT)
		{
			calc_mandelbrot(curr, mlx);
			curr.y++;
		}
		curr.x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
