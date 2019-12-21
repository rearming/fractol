/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:28:25 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/22 21:49:02 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "ft_printf.h"

typedef struct			s_flags
{
	char				zero;
	char				space;
	char				grid;
	char				plus;
	char				minus;
}						t_flags;

typedef struct			s_format
{
	t_flags				flags;
	int					width;
	int					prec;
	int					type_flag;
	int					type;
	int					i;
}						t_format;

typedef struct			s_printf
{
	t_list				*buf;
	va_list				args;
}						t_printf;

union					u_ld
{
	long double			ld_tmp;
	__int128_t			int_tmp;
};

typedef struct			s_ld
{
	union u_ld			ld;
	char				*str;
	int					exp;
	int					negative;
}						t_ld;

#endif
