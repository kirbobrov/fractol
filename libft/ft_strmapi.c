/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:41:11 by kbobrov           #+#    #+#             */
/*   Updated: 2016/12/10 17:05:05 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*bf;
	unsigned int	i;

	i = 0;
	bf = NULL;
	if (!s || !f)
		return (NULL);
	bf = ft_strdup(s);
	if (bf)
	{
		while (*s)
		{
			bf[i] = f(i, *s);
			s++;
			i++;
		}
		bf[i] = '\0';
	}
	return (&bf[0]);
}
