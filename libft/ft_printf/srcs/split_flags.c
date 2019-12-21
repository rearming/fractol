/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:54:17 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/22 21:49:02 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			count_parts(const char *str, char delim)
{
	int			count;
	size_t		i;

	i = 0;
	count = 0;
	str[i] == delim ? i++ : i;
	str[i] == delim ? i++ : i;
	count++;
	while (str[i])
	{
		if (str[i] == delim && str[i + 1])
		{
			if (str[i + 1] == delim)
				i++;
			count++;
		}
		i++;
	}
	return (count);
}

char		*add_part(const char *str, size_t *start, char delim)
{
	char		*part;
	size_t		begin;
	size_t		end;

	begin = 0;
	end = 0;
	str[*start + begin] == delim ? begin++ : begin;
	str[*start + begin] == delim ? begin++ : begin;
	while (str[*start + begin + end] && str[*start + begin + end] != delim)
		end++;
	if (str[*start + begin + end] == delim
		&& str[*start + begin + end + 1] == 0)
		end++;
	part = ft_strsub(str, *start, end + begin);
	*start += end + begin;
	return (part);
}

char		**split_flags(const char *str, char delim)
{
	size_t		start;
	int			i;
	int			parts;
	char		**result;

	if (!str)
		return (NULL);
	parts = count_parts(str, delim);
	if (!(result = (char**)malloc(sizeof(char*) * (parts + 1))))
		return (NULL);
	result[parts] = 0;
	start = 0;
	i = 0;
	while (i < parts)
		result[i++] = add_part(str, &start, delim);
	return (result);
}
