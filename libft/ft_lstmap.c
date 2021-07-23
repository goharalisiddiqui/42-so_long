/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:03:38 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/06/21 19:24:22 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lstmap_check(t_list *elem, void (*del)(void *))
{
	if (elem == NULL)
	{
		ft_lstclear(&elem, del);
		return (1);
	}
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_top;
	t_list	*new_elem;

	new_top = NULL;
	if (lst != NULL)
	{
		new_elem = ft_lstnew(f((*lst).content));
		if (ft_lstmap_check(new_elem, del))
			return (NULL);
		new_top = new_elem;
		lst = (*lst).next;
	}
	while (lst != NULL)
	{
		(*new_elem).next = ft_lstnew(f((*lst).content));
		new_elem = (*new_elem).next;
		if (ft_lstmap_check(new_elem, del))
			return (NULL);
		lst = (*lst).next;
	}
	return (new_top);
}
