/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:46:42 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/06/25 17:28:51 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((*(s1 + i) || *(s2 + i)) && i < n)
	{
		if ((unsigned char)*(s1 + i) > (unsigned char)*(s2 + i))
			return (1);
		else if ((unsigned char)*(s1 + i) < (unsigned char)*(s2 + i))
			return (-1);
		i++;
	}
	return (0);
}
