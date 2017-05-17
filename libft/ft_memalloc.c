/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 11:42:20 by kbobrov           #+#    #+#             */
/*   Updated: 2016/12/09 17:38:40 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*buf;

	buf = (void*)malloc(sizeof(void*) * size);
	if (buf == NULL)
		return (NULL);
	ft_bzero(buf, size);
	return (buf);
}
