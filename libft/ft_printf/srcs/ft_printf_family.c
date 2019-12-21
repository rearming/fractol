/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:17:15 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/22 21:49:02 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		out_count_symbols;
	char	*result_str;

	va_start(g_pf.args, format);
	result_str = get_formatted_string(&out_count_symbols, format);
	write(1, result_str, out_count_symbols);
	free(result_str);
	va_end(g_pf.args);
	return (out_count_symbols);
}

int		ft_printf_fd(int fd, const char *format, ...)
{
	int		out_count_symbols;
	char	*result_str;

	va_start(g_pf.args, format);
	result_str = get_formatted_string(&out_count_symbols, format);
	write(fd, result_str, out_count_symbols);
	free(result_str);
	va_end(g_pf.args);
	return (out_count_symbols);
}

int		ft_sprintf(char **out_str, const char *format, ...)
{
	int		out_count_symbols;

	va_start(g_pf.args, format);
	*out_str = get_formatted_string(&out_count_symbols, format);
	va_end(g_pf.args);
	return (out_count_symbols);
}
