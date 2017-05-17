/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:01:25 by kbobrov           #+#    #+#             */
/*   Updated: 2016/12/10 19:02:32 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace(char str)
{
	return (str == '\t' || str == ' ' || str == '\n');
}

char		*ft_strtrim(char const *s)
{
	int		i;
	char	*buf;
	int		len;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (isspace(s[i]))
		i++;
	len = ft_strlen(s) - 1;
	while (len > i && isspace(s[len]))
		len--;
	if (len < i)
		return (buf = ft_strdup(""));
	return (buf = ft_strsub(s, i, len - i + 1));
}
