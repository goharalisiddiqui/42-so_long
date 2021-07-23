/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:57:14 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/06/25 17:19:41 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*mem;

	i = 0;
	mem = malloc(count * size);
	if (mem == NULL)
		return (NULL);
	while (i < (count * size))
	{
		*(mem + i) = (unsigned char)0;
		i++;
	}
	return (mem);
}
