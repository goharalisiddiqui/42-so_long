/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_plistfuncs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:04:27 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/27 18:08:39 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


t_plist	*ft_plstlast(t_plist *lst)
{
	while (lst != NULL && (*lst).next != NULL)
		lst = (*lst).next;
	return (lst);
}

t_plist	*ft_plstnew(void *content, char ident)
{
	t_plist	*elem;

	elem = malloc(sizeof(t_plist));
	if (elem == NULL)
		return (NULL);
	(*elem).content = content;
	(*elem).ident = ident;
	(*elem).next = NULL;
	return (elem);
}

void	ft_plstadd_back(t_plist **lst, t_plist *new)
{
	t_plist	*elem;

	if (*lst != NULL)
	{
		elem = ft_plstlast(*lst);
		(*elem).next = new;
	}
	else
		*lst = new;
}
void	ft_plstclear(t_plist **lst, void (*del)(void*))
{
	t_plist	*buff;

	while (*lst != NULL)
	{
		del((**lst).content);
		buff = (**lst).next;
		free(*lst);
		*lst = buff;
	}
	lst = NULL;
}

void	ft_plstiter(t_plist *lst, void (*f)(void *, char))
{
	while (lst != NULL)
	{
		f((*lst).content, (*lst).ident);
		lst = (*lst).next;
	}
}

