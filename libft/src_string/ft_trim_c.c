/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:30:53 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/22 14:17:30 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_trim_c(const char *str, char breaker)
{
	char	*result;
	int64_t	res_len;
	int64_t	last_char;

	if (!str)
		return (NULL);
	while (*str == breaker)
		str++;
	last_char = (t_ft_uint64)ft_strchr(str, breaker);
	if (last_char)
		res_len = (t_ft_uint64)ft_strchr(str, breaker) - (t_ft_uint64)str;
	else
		res_len = ft_strlen(str);
	if (!(result = (char*)malloc(sizeof(char) * res_len + 1)))
		return (NULL);
	result[res_len] = 0;
	return (ft_memcpy(result, str, res_len));
}
