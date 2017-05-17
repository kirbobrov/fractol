/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:23:55 by kbobrov           #+#    #+#             */
/*   Updated: 2016/12/13 19:02:02 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		i;

	i = ft_strlen(str) + 1;
	while (i-- > 0)
		if (str[i] == (char)ch)
			return ((char*)(&str[i]));
	return (0);
}
