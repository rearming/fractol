/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:44:58 by sleonard          #+#    #+#             */
/*   Updated: 2019/08/01 11:04:43 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			cut_result(char **line, char **back_str)
{
	size_t	len;
	char	*tmp;

	*line = NULL;
	len = 0;
	while ((*back_str)[len] != '\n' && (*back_str)[len] != '\0')
		len++;
	*line = ft_strsub(*back_str, 0, len);
	tmp = ft_strsub(*back_str, len + 1, ft_strlen(*back_str));
	ft_strdel(back_str);
	if (tmp && tmp[0] != '\0')
		*back_str = tmp;
	return (1);
}

char		**lstsearch(t_list *list, int fd)
{
	while (list)
	{
		if (list->content_size == (size_t)fd)
			return ((char**)&(list->content));
		list = list->next;
	}
	return (NULL);
}

char		**lstadd(t_list **lst, int fd)
{
	t_list	*tmp;

	if (!*lst)
	{
		*lst = ft_lstnew(NULL, fd);
		(*lst)->content_size = fd;
		return ((char**)&((*lst)->content));
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_lstnew(NULL, fd);
	tmp->next->content_size = fd;
	return ((char**)&(tmp->next->content));
}

int			get_next_line(int fd, char **line)
{
	static t_list	*back_lst;
	char			*tmp_s;
	char			**back_str;
	char			buf[BUFF_SIZE + 1];
	int				read_res;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!(back_str = lstsearch(back_lst, fd)))
		back_str = lstadd(&back_lst, fd);
	while ((read_res = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[read_res] = '\0';
		if (!(*back_str))
			(*back_str) = ft_strnew(BUFF_SIZE + 1);
		tmp_s = ft_strjoin(*back_str, buf);
		free(*back_str);
		(*back_str) = tmp_s;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (read_res == 0 && (!(*back_str) || (*back_str)[0] == '\0'))
		return (0);
	return (cut_result(line, back_str));
}
