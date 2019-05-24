/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:29:56 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/13 11:19:47 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		skip_obs(const char *str, size_t i, char obs)
{
	while (str[i] == obs)
		i++;
	return (i);
}

static size_t	count_words(const char *str, char obs)
{
	size_t	words_nb;
	size_t	i;

	i = 0;
	words_nb = 0;
	if (ft_strlen(str) == 0)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == obs)
		{
			i = skip_obs(str, i, obs);
			words_nb++;
		}
		else
			i++;
	}
	if (str[i] == '\0' && str[i - 1] != obs)
		words_nb++;
	if (str[0] == obs)
		words_nb--;
	return (words_nb);
}

static size_t	get_word_len(const char *str, size_t *i, int len, char obs)
{
	size_t	local_i;

	local_i = *i;
	while (str[local_i] != '\0' && str[local_i] != obs)
	{
		local_i++;
		len++;
	}
	*i = local_i;
	return (len);
}

static char		**ft_clean(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
	return (NULL);
}

char			**ft_strsplit(char const *str, char obs)
{
	char	**words_arr;
	size_t	words_nbr;
	size_t	words_i;
	size_t	i;
	size_t	len;

	words_i = 0;
	len = 0;
	if (!str)
		return (NULL);
	words_nbr = count_words(str, obs);
	if (!(words_arr = (char**)malloc(sizeof(char*) * (words_nbr + 1))))
		return (NULL);
	words_arr[words_nbr] = 0;
	i = skip_obs(str, 0, obs);
	while (words_i < words_nbr)
	{
		len = get_word_len(str, &i, len, obs);
		if (!(words_arr[words_i] = ft_strsub(str, i - len, len)))
			return (ft_clean(words_arr));
		i = skip_obs(str, i, obs);
		len = 0;
		words_i++;
	}
	return (words_arr);
}
