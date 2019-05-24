/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:23:40 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/13 11:19:47 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *dest, int c, size_t n)
{
	char			chr;
	unsigned char	*arr;
	int				i;

	i = 0;
	chr = c;
	arr = dest;
	if (n == 0)
		return (dest);
	while (i < (int)n)
	{
		arr[i] = chr;
		i++;
	}
	return (dest);
}
