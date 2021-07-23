/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:47:50 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/06/21 20:15:21 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strtrim_store(char *str, const char *s1, int start, int end)
{
	int	i;

	i = 0;
	while (i <= (end - start) && (end != start))
	{
		*(str + i) = *(s1 + start + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen((char *)s1);
	while (ft_strchr(set, (int)*(s1 + start)) != NULL && *(s1 + start))
		start++;
	while (ft_strchr(set, (int)*(s1 + end)) != NULL && *(s1 + start))
		end--;
	if (end == start)
		str = malloc(sizeof(char));
	else
		str = malloc(((end - start) + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str = ft_strtrim_store(str, s1, start, end);
	return (str);
}
