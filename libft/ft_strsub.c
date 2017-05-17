/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:00:00 by kbobrov           #+#    #+#             */
/*   Updated: 2016/12/10 18:08:17 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int star, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	ln;
	char	*buf;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	ln = ft_strlen(s);
	if (star > ln || ln < (star + len))
		return (NULL);
	buf = 0;
	buf = (char *)malloc(sizeof(*buf) * (len + 1));
	if (buf)
	{
		while (((unsigned char *)s)[i] && i < star)
			i++;
		while (j < len)
			buf[j++] = ((char *)s)[i++];
		buf[j] = '\0';
	}
	return (buf);
}
