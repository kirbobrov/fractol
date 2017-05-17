/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:41:11 by kbobrov           #+#    #+#             */
/*   Updated: 2016/12/10 17:07:37 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	char	*ps1;
	char	*ps2;
	int		n;

	if (*s2 == '\0')
		return ((char *)s1);
	ps1 = (char *)s1;
	ps2 = (char *)s2;
	n = ft_strlen(ps2);
	i = 0;
	while (ps1[i] != '\0' && (i + n) <= len)
	{
		if (ft_strncmp(s1 + i, s2, n) == 0)
		{
			return (ps1 + i);
		}
		i++;
	}
	return (NULL);
}
