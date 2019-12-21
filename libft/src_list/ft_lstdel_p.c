/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:29:22 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/22 16:42:20 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_p(t_list **begin)
{
	t_list *tmp;

	if (!begin)
		return ;
	while (*begin)
	{
		tmp = *begin;
		(*begin) = (*begin)->next;
		free(tmp);
	}
}
