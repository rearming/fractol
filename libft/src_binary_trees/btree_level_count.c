/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:26:57 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/23 18:48:24 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btrees.h"
#include "libft.h"

int			btree_level_count(t_btree *root)
{
	int		left_levels;
	int		right_levels;
	int		result;

	result = 0;
	if (root)
	{
		left_levels = btree_level_count(root->left);
		right_levels = btree_level_count(root->right);
		result = ft_max(left_levels + 1, right_levels + 1);
	}
	return (result);
}
