/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:53:31 by kbobrov           #+#    #+#             */
/*   Updated: 2017/02/19 15:44:07 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrjoin(char *s1, char const *s2)
{
	char *temp;

	temp = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (temp);
}

int		ft_lsd(char **str, char **file)
{
	char	*st;
	char	*temp;

	if ((temp = ft_strchr(*str, '\n')))
	{
		*temp = '\0';
		*file = ft_strdup(*str);
		st = ft_strdup(temp + 1);
		free(*str);
		*str = st;
		st = NULL;
		return (1);
	}
	return (0);
}

int		ft_read_file(int fd, char **file, t_str *l)
{
	char	*buf;
	int		re;

	buf = ft_strnew(BUFF_SIZE);
	if (l->s && ft_lsd(&(l->s), file))
		return (1);
	while ((re = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[re] = '\0';
		l->s = ft_strrjoin(l->s, buf);
	}
	if (l->s && ft_lsd(&(l->s), file))
	{
		ft_strdel(&buf);
		return (1);
	}
	if (!(l->s) || (!(*l->s) && !(*buf)))
	{
		ft_strdel(&buf);
		return (0);
	}
	free(buf);
	*file = ft_strdup(l->s);
	ft_strdel(&l->s);
	return (1);
}

int		get_next_line(const int fd, char **file)
{
	static t_str	st[53];
	t_str			*tmp;
	int				re;
	char			*buf;

	buf = ft_strnew(BUFF_SIZE);
	if ((re = read(fd, buf, 0)) < 0)
		return (-1);
	tmp = &(st[fd % 53]);
	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	return (ft_read_file(fd, file, tmp));
	return (0);
}
