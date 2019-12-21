/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_delete_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:31:49 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/25 17:43:47 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btrees.h"

static t_avl_tree	*avl_findmin(t_avl_tree *node)
{
	return (node->left ? avl_findmin(node->left) : node);
}

static t_avl_tree	*avl_removemin(t_avl_tree *node)
{
	if (!node->left)
		return (node->right);
	node->left = avl_removemin(node->left);
	avl_rebalance(&node);
	return (node);
}

inline static void	fuck_norme_delete_node(t_avl_tree **root,
						void (*data_del_func)(void*))
{
	t_avl_tree	*q_node;
	t_avl_tree	*r_node;
	t_avl_tree	*min_node;

	q_node = (*root)->left;
	r_node = (*root)->right;
	data_del_func((*root)->data);
	free(*root);
	*root = NULL;
	if (!r_node)
	{
		*root = q_node;
		return ;
	}
	min_node = avl_findmin(r_node);
	min_node->right = avl_removemin(r_node);
	min_node->left = q_node;
	avl_rebalance(&min_node);
	*root = min_node;
}

void				avl_delete_node(t_avl_tree **root, void *data,
						int (*cmpfunc)(void*, void*),
						void (*data_del_func)(void*))
{
	if (!root || !*root)
		return ;
	if (cmpfunc(data, (*root)->data) > 0)
		avl_delete_node(&(*root)->right, data, cmpfunc, data_del_func);
	else if (cmpfunc(data, (*root)->data) < 0)
		avl_delete_node(&(*root)->left, data, cmpfunc, data_del_func);
	else
		return (fuck_norme_delete_node(root, data_del_func));
	avl_rebalance(root);
}
