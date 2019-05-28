/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:04:25 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/28 19:04:25 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex		complex_add(t_complex a, t_complex b)
{
	t_complex c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

t_complex		complex_sqr(t_complex a)
{
	t_complex c;

	c.x = a.x * a.x - a.y * a.y;
	c.y = 2 * a.x * a.y;
	return c;
}

double			complex_sqrt(t_complex a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}
