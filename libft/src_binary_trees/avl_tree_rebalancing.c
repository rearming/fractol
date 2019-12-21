/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree_rotations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:24:28 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/25 11:33:10 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btrees.h"

static void	avl_rotate_right(t_avl_tree **p_node)
{
	t_avl_tree	*q_node;

	q_node = (*p_node)->left;
	(*p_node)->left = q_node->right;
	q_node->right = *p_node;
	avl_fixheight(*p_node);
	avl_fixheight(q_node);
	*p_node = q_node;
}

static void	avl_rotate_left(t_avl_tree **q_node)
{
	t_avl_tree	*p_node;

	p_node = (*q_node)->right;
	(*q_node)->right = p_node->left;
	p_node->left = *q_node;
	avl_fixheight(*q_node);
	avl_fixheight(p_node);
	*q_node = p_node;
}

void		avl_rebalance(t_avl_tree **p_node)
{
	avl_fixheight(*p_node);
	if (avl_bfactor(*p_node) == 2)
	{
		if (avl_bfactor((*p_node)->right) < 0)
			avl_rotate_right(&(*p_node)->right);
		avl_rotate_left(p_node);
		return ;
	}
	if (avl_bfactor(*p_node) == -2)
	{
		if (avl_bfactor((*p_node)->left) > 0)
			avl_rotate_left(&(*p_node)->left);
		avl_rotate_right(p_node);
	}
}
