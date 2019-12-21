/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_btree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:11:15 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/25 16:21:36 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btrees.h"

void	free_btree(t_avl_tree *root, void (*data_del_func)(void*))
{
	if (!root)
		return ;
	free_btree(root->left, data_del_func);
	free_btree(root->right, data_del_func);
	data_del_func(root->data);
	free(root);
}
