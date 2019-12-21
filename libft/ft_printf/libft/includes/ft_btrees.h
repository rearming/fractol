/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btrees.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:46:01 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/23 18:02:14 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FT_BTREES_H
# define LIBFT_FT_BTREES_H

# include <stdlib.h>
# include "ft_structs.h"

t_btree		*btree_create_node(void *item);
void		btree_insert_data(t_btree **root, void *item,
				int (*cmpfunc)(void *, void *));
void		btree_apply_preorder(t_btree *root, void (*applyf)(void*));
void		btree_apply_inorder(t_btree *root, void (*applyf)(void*));
void		btree_apply_postorder(t_btree *root, void (*applyf)(void*));
void		*btree_find_item(t_btree *root, void *data_ref,
				int (*cmpfunc)(void *, void *));
int			btree_level_count(t_btree *root);

#endif
