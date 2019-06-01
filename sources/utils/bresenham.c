/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rearming <rearming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:43:12 by rearming          #+#    #+#             */
/*   Updated: 2019/05/31 12:28:41 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		prepare_coords(t_point *start, t_point *end, int steep)
{
	if (steep)
	{
		ft_swap(&start->x, &start->y);
		ft_swap(&end->x, &end->y);
	}
	if (start->x > end->x)
	{
		ft_swap(&start->x, &end->x);
		ft_swap(&start->y, &end->y);
		ft_swap(&start->color, &end->color);
	}
}

void		line_init(t_line *line, t_point *start, t_point *end)
{
	line->start = *start;
	line->end = *end;
	line->delta.x = end->x - start->x;
	line->delta.y = ft_abs(end->y - start->y);
	line->error = line->delta.x / 2;
	line->ystep = (start->y < end->y) ? 1 : -1;
}

void		bresen_line(t_mlx *mlx, t_point start, t_point end)
{
	t_line	line;

	line.steep = ft_abs(end.y - start.y) > ft_abs(end.x - start.x);
	prepare_coords(&start, &end, line.steep);
	line_init(&line, &start, &end);
	while (start.x <= end.x)
	{
		line.point.x = line.steep ? start.y : start.x;
		line.point.y = line.steep ? start.x : start.y;
		image_put_pixel(mlx->img, line.point, start.color);
		line.error -= line.delta.y;
		if (line.error < 0)
		{
			start.y += line.ystep;
			line.error += line.delta.x;
		}
		start.x++;
	}
}
