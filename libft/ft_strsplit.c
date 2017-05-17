/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 18:34:05 by kbobrov           #+#    #+#             */
/*   Updated: 2016/12/11 16:30:29 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static int	ft_wordlen(char const *str, char c, int i)
{
	int	count;

	count = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i])
	{
		count++;
		i++;
	}
	return (count);
}

static char	**get_array(char const *s, char c, int j, char **res)
{
	int	i;
	int	k;

	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			k = 0;
			res[j] = (char*)malloc(sizeof(char) * ft_wordlen(s, c, i));
			if (!res[j])
			{
				ft_strdel(res);
				return (0);
			}
			while (s[i] != c && s[i])
				res[j][k++] = s[i++];
			res[j++][k] = '\0';
		}
	}
	res[j] = 0;
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	char	**res;

	if (!s)
		return (0);
	len = ft_words((char *)s, c);
	res = (char **)malloc(sizeof(*res) * (len + 1));
	if (!res)
		return (0);
	j = 0;
	i = 0;
	res = get_array(s, c, i, res);
	return (res);
}
