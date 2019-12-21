/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:37:14 by sleonard          #+#    #+#             */
/*   Updated: 2019/08/01 11:04:43 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	get_begin_index(char const *str)
{
	size_t	i;

	i = 0;
	while ((str[i] == ' ' || str[i] == '\n'
		|| str[i] == '\t') && (str[i] != '\0'))
		i++;
	return (i);
}

static size_t	get_end_index(char const *str)
{
	size_t	len;

	len = ft_strlen(str) - 1;
	while ((str[len] == ' ' || str[len] == '\n'
		|| str[len] == '\t' || str[len] == '\0') && len != 0)
	{
		len--;
	}
	return (len);
}

static char		*handle_zero(void)
{
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) + 1)))
		return (NULL);
	res[0] = '\0';
	return (res);
}

char			*ft_strtrim(char const *str)
{
	char	*res;
	size_t	begin;
	size_t	end;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	begin = get_begin_index(str);
	end = get_end_index(str);
	if (str[0] == '\0')
		return ((char*)str);
	if (end == 0)
		return (handle_zero());
	if (!(res = (char*)malloc(sizeof(char) * (end - begin) + 2)))
		return (NULL);
	while (begin <= end)
	{
		res[i] = str[begin];
		begin++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
