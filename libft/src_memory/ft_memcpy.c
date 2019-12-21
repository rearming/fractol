/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:59:53 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/24 16:27:38 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_c;
	char		*src_c;

	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return (dest);
	dest_c = (char*)dest;
	src_c = (char*)src;
	while (n > 0)
	{
		*(dest_c) = *(src_c);
		dest_c++;
		src_c++;
		n--;
	}
	return (dest);
}
