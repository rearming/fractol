/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_filler_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:41:12 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/23 16:13:24 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fill_differ(int differ, t_format format)
{
	char	*temp;

	if (differ)
	{
		temp = ft_strnew(differ);
		if (format.flags.zero)
			ft_memset(temp, '0', differ);
		else
			ft_memset(temp, ' ', differ);
		ft_lstaddback(&g_pf.buf, temp, differ + 1);
		free(temp);
	}
}

char		*get_prefix(char *arg, t_format *format)
{
	if (!arg)
		return (0);
	if (arg[0] == '-')
	{
		while (*(arg + 1))
		{
			*arg = (*(arg + 1));
			arg++;
		}
		*arg = 0;
		format->width--;
		return (ft_strdup("-"));
	}
	if (format->flags.plus)
		return
		(ft_strdup((format->flags.space && (ft_isdigit(arg[0])) ? " +" : "+")));
	if (format->flags.space)
	{
		format->width--;
		return (ft_strdup(" "));
	}
	return (0);
}

char		*get_base_prefix(char *arg, t_format *format)
{
	if (!arg)
		return (0);
	if ((format->flags.grid && ft_atoll_base(arg, 16)) || format->type == PTR)
	{
		if ((format->width != NO_VALUE && format->width != NO_FLAG)
			|| format->type == PTR)
			format->width -= format->type == OCTAL ? 1 : 2;
		else
			format->prec -= format->type == OCTAL ? 1 : 2;
		if (format->type == S_HEX || format->type == PTR)
			return (ft_strdup("0x"));
		if (format->type == B_HEX)
			return (ft_strdup("0X"));
		if (format->type == OCTAL)
			return (ft_strdup("0"));
	}
	return (0);
}

void		add_prefix(t_format format, int differ, char *prefix, int len)
{
	if (!format.flags.minus)
	{
		if (!format.flags.zero && format.width > len)
		{
			fill_differ(differ, format);
			prefix ? ft_lstaddback(&g_pf.buf, prefix, ft_strlen(prefix) + 1)
			: 0;
		}
		else
		{
			prefix ? ft_lstaddback(&g_pf.buf, prefix, ft_strlen(prefix) + 1)
			: 0;
			fill_differ(differ, format);
		}
	}
	else
		prefix ? ft_lstaddback(&g_pf.buf, prefix, ft_strlen(prefix) + 1) : 0;
}

char		*add_precision_zeros(t_format format, int *len, char *arg)
{
	char	*temp;

	if (format.prec != NO_FLAG)
	{
		temp = ft_strnew((*len) < format.prec ? format.prec : (*len));
		ft_memcpy(&temp[(*len) < format.prec ? format.prec - (*len) : 0],
				arg, (*len));
		ft_memset(temp, '0', (*len) < format.prec ? format.prec - (*len) : 0);
		(*len) = format.prec > (*len) ? format.prec : (*len);
	}
	else
		temp = ft_strdup(arg);
	return (temp);
}
