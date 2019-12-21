/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:07:22 by sleonard          #+#    #+#             */
/*   Updated: 2019/08/01 11:04:43 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

# define CHAR 10
# define UCHAR 11
# define SHORT 12
# define USHORT 13
# define INT 14
# define UNSIGNED 15
# define LONG 16
# define LONG_LONG 17
# define ULONG 18
# define ULONG_LONG 19
# define INT_MAX 20
# define DOUBLE 21
# define LDOUBLE 22
# define SIZE_T 23
# define STRING 24
# define PTR 25
# define OCTAL 26
# define S_HEX 27
# define B_HEX 28
# define BINARY 29
# define DATE 30
# define NON_PRINT 31
# define PERCENT 32
# define WCHAR 33
# define WSTRING 34

# define NO_FLAG -50
# define NO_VALUE -51
# define BREAK -3

# ifdef __linux__
#  define INTMAX_T __intmax_t
# else
#  define INTMAX_T intmax_t
# endif

#endif
