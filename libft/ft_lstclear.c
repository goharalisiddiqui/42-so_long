/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:01:19 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/06/21 19:07:38 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*buff;

	while (*lst != NULL)
	{
		del((**lst).content);
		buff = (**lst).next;
		free(*lst);
		*lst = buff;
	}
	lst = NULL;
}
