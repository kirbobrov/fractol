/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:23:00 by kbobrov           #+#    #+#             */
/*   Updated: 2016/12/10 18:11:00 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long s)
{
	long	i;

	i = 1;
	if (s < 0)
	{
		s = -s;
		i++;
	}
	while ((s = s / 10))
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	long	len;
	long	m;
	char	*bf;

	m = n;
	len = ft_len(m);
	if (n < 0)
		m = -m;
	bf = ft_strnew(len);
	if (!bf)
		return (NULL);
	if (n < 0)
		bf[0] = '-';
	while (m > 0)
	{
		bf[len - 1] = m % 10 + '0';
		m = m / 10;
		len--;
	}
	if (n == -0)
		bf[0] = '0';
	return (bf);
}
