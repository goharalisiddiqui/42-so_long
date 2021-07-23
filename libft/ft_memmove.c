/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:55:25 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/06/27 15:04:05 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 1;
	if (src < dst && (((unsigned char *)src + len) > (unsigned char *)dst))
	{
		while (i <= len)
		{
			*((char *)dst + len - i) = *((char *)src + len - i);
			i++;
		}
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, len));
}
