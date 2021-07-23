/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:48:02 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/14 18:17:02 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_vlstadd(t_vlist **lst, int id, char *str)
{
	t_vlist	*elem;
	t_vlist	*lastelem;

	elem = ft_vlstlocdel(lst, id, 0);
	if (elem == NULL)
	{
		elem = malloc(sizeof(t_vlist));
		(*elem).idt = id;
		(*elem).next = NULL;
		if (*lst == NULL)
			*lst = elem;
		else
		{
			lastelem = *lst;
			while ((*lastelem).next != NULL)
				lastelem = (*lastelem).next;
			(*lastelem).next = elem;
		}
	}
	else
		free((*elem).content);
	(*elem).content = str;
}

t_vlist	*ft_vlstlocdel(t_vlist **lst, int fd, int ident)
{
	t_vlist	*elem;
	t_vlist	*prev;

	elem = *lst;
	prev = NULL;
	while (elem != NULL && (*elem).idt != fd)
	{
		prev = elem;
		elem = (*elem).next;
	}
	if (ident == 0)
		return (elem);
	free((*elem).content);
	if (prev != NULL)
		(*prev).next = (*elem).next;
	else
		*lst = (*elem).next;
	free(elem);
	return (NULL);
}
