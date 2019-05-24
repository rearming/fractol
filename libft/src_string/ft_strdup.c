/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:42:23 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/13 11:19:47 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dest;
	char	*ptr;

	len = ft_strlen(src) + 1;
	if (!(dest = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	ptr = dest;
	while (*src)
		*dest++ = *src++;
	*dest++ = *src++;
	return (ptr);
}
