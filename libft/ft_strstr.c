/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:31:47 by kbobrov           #+#    #+#             */
/*   Updated: 2016/12/13 19:04:05 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	char	*ps1;
	char	*ps2;
	size_t	len;

	if (!(*little))
		return ((char *)big);
	ps1 = (char *)big;
	ps2 = (char *)little;
	i = 0;
	len = ft_strlen(little);
	while (ps1[i])
	{
		if (ft_strncmp(&ps1[i], little, len) == 0)
		{
			return (ps1 + i);
		}
		i++;
	}
	return (NULL);
}
