/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:59:08 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/31 14:25:51 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		rotate_z(t_point *point, t_point center, double angle)
{
	t_point		temp;

	temp = *point;
	point->x = center.x + (point->x - center.x)
			* cos(angle) - (point->y - center.y) * sin(angle);
	point->y = center.y + (temp.y - center.y)
			* cos(angle) + (temp.x - center.x) * sin(angle);
}
