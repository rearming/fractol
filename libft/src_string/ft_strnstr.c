/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:24:48 by sleonard          #+#    #+#             */
/*   Updated: 2019/08/01 11:04:43 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_entering(const char *haystack, char *needle)
{
	size_t	i;

	i = 0;
	while (needle[i] != '\0')
	{
		if (haystack[i] != needle[i])
			return (0);
		i++;
	}
	return (1);
}

char		*ft_strnstr(const char *haystack,
					const char *needle, size_t len)
{
	size_t	limit;
	char	*ptr;

	limit = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	if (len == 0)
		return (0);
	while (haystack[limit] != '\0' && limit < len)
	{
		if (haystack[limit] == needle[0])
		{
			ptr = (char*)&haystack[limit];
			if (check_entering(&haystack[limit], (char*)needle) && limit <= len)
			{
				if (ft_strlen(needle) > len - limit)
					return (NULL);
				return (ptr);
			}
		}
		limit++;
	}
	return (NULL);
}
