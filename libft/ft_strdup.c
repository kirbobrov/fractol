/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:41:21 by kbobrov           #+#    #+#             */
/*   Updated: 2016/12/10 17:14:52 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		count;
	int		len;
	char	*str;

	len = ft_strlen(src);
	str = (char*)malloc(sizeof(*str) * (len + 1));
	count = 0;
	if (str != 0)
	{
		while (count < len)
		{
			str[count] = src[count];
			count++;
		}
		str[count] = '\0';
		return (str);
	}
	else
		return (NULL);
}
