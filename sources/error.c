/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:34:57 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/24 14:34:57 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		raise_error(int code)
{
	if (code == ERR_INV_ARGS)
		perror("Number of args isn't 1.\n");
	if (code == ERR_INV_FILE)
		perror("Invalid file.\n");
	if (code == ERR_INV_MAP)
		write(1, "Valid map contains only numbers and whitespaces!\n", 62);
	if (code == ERR_MALLOC)
		write(1, "Malloc failed.\n", 16);
	if (code == ERR_MLX_INIT)
		write(1, "Mlx init failed.\n", 20);
	exit(code);
}
