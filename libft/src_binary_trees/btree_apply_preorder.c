/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_preorder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:11:07 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/23 19:11:07 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btrees.h"

void	btree_apply_preorder(t_btree *root, void (*applyf)(void*))
{
	if (!root)
		return ;
	applyf(root->data);
	btree_apply_preorder(root->left, applyf);
	btree_apply_preorder(root->right, applyf);
}
