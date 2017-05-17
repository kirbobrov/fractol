/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:36:25 by kbobrov           #+#    #+#             */
/*   Updated: 2016/12/13 19:01:07 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *ptr)
{
	int	i;
	int	s;
	int	bf;

	i = 0;
	s = 1;
	bf = 0;
	while (ptr[i] == ' ' || ptr[i] == '\t' || ptr[i] == '\v'
			|| ptr[i] == '\f' || ptr[i] == '\r' || ptr[i] == '\n')
		i++;
	if (ptr[i] == '+' || ptr[i] == '-')
	{
		if (ptr[i] == '-')
			s = -1;
		i++;
	}
	while (ptr[i] && ft_isdigit(ptr[i]) == 1)
		bf = (bf * 10) + (ptr[i++] - '0');
	return (bf * s);
}
