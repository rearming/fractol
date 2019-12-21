/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_postorder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:33:43 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/23 17:29:28 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btrees.h"

void	btree_apply_postorder(t_btree *root, void (*applyf)(void*))
{
	if (!root)
		return ;
	btree_apply_postorder(root->left, applyf);
	btree_apply_postorder(root->right, applyf);
	applyf(root->data);
}
