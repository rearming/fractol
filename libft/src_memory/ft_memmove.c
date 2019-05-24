/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:51:35 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/13 11:19:47 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char		*p_dst;
	const unsigned char *p_src;
	unsigned char		*p_ldest;
	const unsigned char *p_lsrc;

	p_dst = dest;
	p_src = src;
	if (dest < src)
	{
		while (num-- > 0)
			*p_dst++ = *p_src++;
	}
	else
	{
		p_ldest = p_dst + (num - 1);
		p_lsrc = p_src + (num - 1);
		while (num--)
			*p_ldest-- = *p_lsrc--;
	}
	return (dest);
}
