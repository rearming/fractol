/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_insert_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:56:37 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/25 11:28:01 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btrees.h"

void		avl_insert_data(t_avl_tree **root, void *data,
							int (*cmpf)(void*, void*))
{
	if (!root)
		return ;
	if (!*root)
	{
		*root = avl_create_node(data);
		return ;
	}
	if (cmpf(data, (*root)->data) >= 0)
		avl_insert_data(&(*root)->right, data, cmpf);
	else
		avl_insert_data(&(*root)->left, data, cmpf);
	avl_rebalance(root);
}
