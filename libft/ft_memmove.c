/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:40:46 by kbobrov           #+#    #+#             */
/*   Updated: 2016/12/10 18:24:20 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	int		s;

	if (dst < src)
	{
		i = 1;
		s = 1;
	}
	else
	{
		i = len;
		s = -1;
	}
	while (i > 0 && i <= len)
	{
		((unsigned char*)dst)[i - 1] = ((unsigned char*)src)[i - 1];
		i += s;
	}
	return (dst);
}
