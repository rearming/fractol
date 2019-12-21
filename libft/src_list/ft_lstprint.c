/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:27:54 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/22 16:28:18 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	For fflush()
*/
#include <stdio.h>

void	ft_lstprint(t_list *begin, void (*print_function)(t_list*))
{
	while (begin)
	{
		ft_putstr("{");
		print_function(begin);
		fflush(stdout);
		ft_putchar('}');
		ft_putstr(" -> ");
		begin = begin->next;
	}
	ft_putstr("null\n");
}
