/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:45:56 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/06/21 20:00:32 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	ind;

	ind = ft_strlen((char *)s);
	while (ind >= 0)
	{
		if (*(s + ind) == c)
			return ((char *)(s + ind));
		ind--;
	}
	return (NULL);
}
