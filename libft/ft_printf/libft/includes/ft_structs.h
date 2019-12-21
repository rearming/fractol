/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:32:49 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/23 11:45:51 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*data;
}					t_btree;

enum	e_rb_color
{
	RB_BLACK,
	RB_RED
};

typedef struct		s_rb_tree
{
	struct s_rb_tree	*parent;
	struct s_rb_tree	*left;
	struct s_rb_tree	*right;
	void				*data;
	enum e_rb_color		color;
}					t_rb_tree;

#endif
