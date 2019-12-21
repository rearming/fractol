/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:34:08 by sleonard          #+#    #+#             */
/*   Updated: 2019/12/11 13:34:12 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		cut_result(char **backup, char **line)
{
	const int	len = ft_strlen_char(*backup, '\n');
	char		*tmp_s;

	*line = ft_strsub(*backup, 0, len + 1);
	(*line)[len] = '\0';
	tmp_s = ft_strsub(*backup, len + 1, ft_strlen(*backup) - len);
	free(*backup);
	if (tmp_s)
		*backup = tmp_s;
	return (1);
}

int				gnl(int fd, char **line)
{
	static char		*backup = NULL;
	char			buf[BUFF_SIZE + 1];
	char			*tmp_str;
	int				read_num;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!backup)
	{
		if (!(backup = malloc(sizeof(char))))
			return (-1);
		backup[0] = 0;
	}
	while ((read_num = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[read_num] = '\0';
		tmp_str = ft_strjoin(backup, buf);
		free(backup);
		backup = tmp_str;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if ((read_num == 0 && !backup) || backup[0] == '\0')
		return (0);
	return (cut_result(&backup, line));
}
