/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 20:01:29 by kbobrov           #+#    #+#             */
/*   Updated: 2016/12/13 19:29:59 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*res;

	if (!lst || !f)
		return (0);
	tmp = f(lst);
	res = tmp;
	while (lst->next)
	{
		tmp->next = f(lst->next);
		if (!tmp->next)
			return (0);
		lst = lst->next;
		tmp = tmp->next;
	}
	return (res);
}
