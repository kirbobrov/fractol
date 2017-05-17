/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:21:12 by kbobrov           #+#    #+#             */
/*   Updated: 2017/02/01 20:30:26 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*buf;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s2) + ft_strlen(s1);
	buf = 0;
	buf = (char *)malloc(sizeof(*buf) * (len + 1));
	if (buf)
	{
		if (s1)
			while (((char *)s1)[i])
			{
				buf[i] = ((char *)s1)[i];
				i++;
			}
		if (s2)
			while (((char *)s2)[j])
				buf[i++] = ((char *)s2)[j++];
		buf[i] = '\0';
	}
	return (buf);
}
