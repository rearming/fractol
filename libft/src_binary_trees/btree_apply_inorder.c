/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_inorder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:29:19 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/23 16:31:23 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btrees.h"

void	btree_apply_inorder(t_btree *root, void (*applyf)(void*))
{
	if (!root)
		return ;
	btree_apply_inorder(root->left, applyf);
	applyf(root->data);
	btree_apply_inorder(root->right, applyf);
}
