/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:59:53 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/13 11:19:47 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *dest_uchar;
	unsigned char *src_uchar;

	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return (dest);
	dest_uchar = (unsigned char *)dest;
	src_uchar = (unsigned char *)src;
	while (n-- > 0)
		*(dest_uchar++) = *(src_uchar++);
	return (dest);
}
