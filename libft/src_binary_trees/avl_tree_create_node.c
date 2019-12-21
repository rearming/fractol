/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avltree_create_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:08:12 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/24 18:10:59 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btrees.h"

t_avl_tree	*avl_create_node(void *item)
{
	t_avl_tree	*node;

	node = (t_avl_tree*)malloc(sizeof(t_avl_tree));
	node->height = 1;
	node->left = NULL;
	node->right = NULL;
	node->data = item;
	return (node);
}
