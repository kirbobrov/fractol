/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 18:08:47 by kbobrov           #+#    #+#             */
/*   Updated: 2016/12/11 19:36:20 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*bf;

	while (*alst)
	{
		bf = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = bf;
	}
	*alst = NULL;
}
