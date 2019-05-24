/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:15:15 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/13 11:19:47 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!str)
		return (NULL);
	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len)
	{
		res[i] = str[start];
		i++;
		start++;
		len--;
	}
	res[i] = '\0';
	return (res);
}
