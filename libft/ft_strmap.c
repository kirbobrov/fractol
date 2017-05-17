/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 13:25:47 by kbobrov           #+#    #+#             */
/*   Updated: 2016/12/04 16:04:57 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*bf;
	int		i;

	i = 0;
	bf = NULL;
	if (!s || !f)
		return (NULL);
	bf = ft_strdup(s);
	if (bf)
	{
		while (*s)
		{
			bf[i] = f(*s);
			s++;
			i++;
		}
		bf[i] = '\0';
	}
	return (&bf[0]);
}
