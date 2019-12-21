/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:28:34 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/22 16:28:34 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback_p(t_list **list, void *content, size_t content_size)
{
	t_list	*tmp;

	if (!list)
		return ;
	if (!*list)
	{
		*list = ft_lstnew_p(content, content_size);
		(*list)->last = *list;
	}
	else
	{
		tmp = (*list)->last;
		tmp->next = ft_lstnew_p(content, content_size);
		(*list)->last = tmp->next;
	}
}
