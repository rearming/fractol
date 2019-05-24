/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:31:24 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/13 11:19:47 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;

	p_dst = (unsigned char*)dest;
	p_src = (unsigned char*)src;
	while (n > 0)
	{
		if (*(p_src) == (unsigned char)c)
		{
			*(p_dst)++ = *(p_src)++;
			return ((void *)p_dst);
		}
		n--;
		*(p_dst)++ = *(p_src)++;
	}
	return (NULL);
}
