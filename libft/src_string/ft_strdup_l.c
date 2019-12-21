/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:30:34 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/24 17:30:35 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_l(const char *src, size_t len)
{
	char	*result;

	len++;
	if (!(result = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	ft_memcpy(result, src, len);
	return (result);
}
