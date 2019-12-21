/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_find_item.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:43:32 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/23 18:02:14 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btrees.h"

void	*btree_find_item(t_btree *root, void *data_to_find,
			int (*cmpfunc)(void *, void *))
{
	if (!root)
		return (NULL);
	if (cmpfunc(data_to_find, root->data) == 0)
		return (root->data);
	if (cmpfunc(data_to_find, root->data) > 0)
		return (btree_find_item(root->right, data_to_find, cmpfunc));
	else
		return (btree_find_item(root->left, data_to_find, cmpfunc));
}
