/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:13:33 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/31 12:08:01 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "stdio.h"

int		main(void)
{
	//ft_printf("kekes: [%i]\n", 1342);
	printf("double: [%Lf]\n", 4252.0L);
	return (0);
}