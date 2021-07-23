/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 12:36:46 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/06/25 17:32:58 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	size;
	size_t	ind;

	size = ft_strlen(dst);
	if (size > dstsize)
		return (dstsize + ft_strlen((char *)src));
	ind = size;
	if (dstsize > 0)
	{
		while ((ind < (dstsize - 1)) && *(src + ind - size))
		{
			*(dst + ind) = *(src + ind - size);
			ind++;
		}
		*(dst + ind) = '\0';
	}
	return (size + ft_strlen((char *)src));
}
