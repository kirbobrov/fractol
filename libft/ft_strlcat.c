/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:33:23 by kbobrov           #+#    #+#             */
/*   Updated: 2016/12/03 19:46:32 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	ct;

	i = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	j = ft_strlen(src);
	ct = i;
	while (src[i - ct] != '\0' && i < size - 1)
	{
		dst[i] = src[i - ct];
		i++;
	}
	if (ct < size)
		dst[i] = '\0';
	return (ct + j);
}
