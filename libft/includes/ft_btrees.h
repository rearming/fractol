/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btrees.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:46:01 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/25 16:19:30 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FT_BTREES_H
# define LIBFT_FT_BTREES_H

# include <stdlib.h>
# include "ft_structs.h"

t_btree			*btree_create_node(void *item);
void			btree_insert_data(t_btree **root, void *item,
					int (*cmpfunc)(void *, void *));
void			btree_apply_preorder(t_btree *root, void (*applyf)(void*));
void			btree_apply_inorder(t_btree *root, void (*applyf)(void*));
void			btree_apply_postorder(t_btree *root, void (*applyf)(void*));
void			*btree_find_item(t_btree *root, void *data_ref,
					int (*cmpfunc)(void *, void *));
int				btree_level_count(t_btree *root);

/*
**	AVL-tree functions
*/

t_avl_tree		*avl_create_node(void *item);
void			avl_insert_data(t_avl_tree **root, void *data,
					int (*cmpf)(void*, void*));
void			avl_delete_node(t_avl_tree **root, void *data,
					int (*cmpfunc)(void*, void*),
					void (*data_del_func)(void*));
void			free_btree(t_avl_tree *root, void (*data_del_func)(void*));

unsigned char	avl_height(t_avl_tree *node);
int				avl_bfactor(t_avl_tree *node);
void			avl_fixheight(t_avl_tree *node);

void			avl_rebalance(t_avl_tree **p_node);

#endif
