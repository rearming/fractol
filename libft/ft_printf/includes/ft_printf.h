/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 04:17:07 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/22 21:49:02 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <wchar.h>

# include "libft.h"
# include "structs.h"
# include "ft_types.h"
# include "error.h"

extern t_printf	g_pf;

/*
** main functions
*/

int						ft_printf(const char *format, ...);
int						ft_printf_fd(int fd, const char *format, ...);
int						ft_sprintf(char **out_str, const char *format, ...);

void					add_buf_node(char *part);
void					free_list(t_list **list);
char					*get_formatted_string(int *out_symbols_count,
							const char *format);

/*
** output functions
*/

char					*get_buffer(t_list **list, size_t total_len);
char					*get_result_string(t_list **list,
							int *out_symbols_count);

/*
** format parsing functions
*/

t_flags					get_flags(char *part, int *i);
int						get_width(char *part, int *i);
int						get_precision(char *part, int *i);
int						get_type_flag(char *part, int *i);
int						get_type(char *part, int i);
t_format				get_format(char *part);

/*
** formatting functions
*/

void					fill_int_format(t_format format, char *arg);
void					fill_format(t_format format, char *arg);
void					fill_float_format(t_format format, char *arg);
void					fill_text_format(t_format format, char *arg);

/*
**	formatting utils
*/

void					shift_arg(char **arg);
void					fill_differ(int differ, t_format format);
char					*get_prefix(char *arg, t_format *format);
char					*get_base_prefix(char *arg, t_format *format);
void					add_prefix(t_format format,
							int differ, char *prefix, int len);
char					*add_precision_zeros(t_format format,
							int *len, char *arg);

/*
** string functions
*/

void					add_text(char *part, t_format format);
void					add_string(char *part, t_format format);
void					add_char(char *part, t_format format);
void					add_percent(char *part, t_format format);

/*
** int functions
*/

char					*convert_signed_arg(t_format format);
void					add_signed(char *part, t_format format);
void					add_unsigned(char *part, t_format format);
void					add_base(char *part, t_format format);

/*
** debug functions
*/

void					print_format(t_format format);
char					*debug_type(int code);
void					my_tests(void);
void					basic_tests(void);
void					int_prec_tests(void);
void					moulitest(void);
void					leak_check(void);
void					min_leak_check(void);

/*
** error functions
*/

void					raise_error(int err_code);

/*
** split flags function
*/

char					**split_flags(const char *str, char delim);

/*
**	float, double & long double
*/

char					*check_fields(t_ld *ld);
void					add_double(char *part, t_format format);

/*
**	list functions
*/

char					*get_last_node(t_list *list);

#endif
