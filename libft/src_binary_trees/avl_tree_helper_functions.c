/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avltree_helper_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:11:04 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/24 18:14:13 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btrees.h"
#include "libft.h"

unsigned char	avl_height(t_avl_tree *node)
{
	return (node ? node->height : 0);
}

int				avl_bfactor(t_avl_tree *node)
{
	return (avl_height(node->right) - avl_height(node->left));
}

void			avl_fixheight(t_avl_tree *node)
{
	unsigned char	left_height;
	unsigned char	right_height;

	left_height = avl_height(node->left);
	right_height = avl_height(node->right);
	node->height = ft_max(left_height, right_height) + 1;
}
