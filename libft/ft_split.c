/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:48:34 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/06/27 15:04:18 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_split_arr(char *s, char c)
{
	int		num;
	char	**arr;

	num = 0;
	while (*s)
	{
		if (*s != c)
		{
			num++;
			while (*s != c && *s != '\0')
				s++;
		}
		else
			s++;
	}
	arr = malloc((num + 1) * sizeof(char *));
	return (arr);
}

static int	ft_split_store(char **arr, const char *s, char c)
{
	int	num;
	int	i;

	num = 0;
	while (*(s + num) != c && *(s + num))
		num++;
	*arr = malloc((num + 1) * sizeof(char));
	if (*arr == NULL)
	{
		free(*arr);
		return (0);
	}
	i = 0;
	while (i < num)
	{
		*(*arr + i) = *(s + i);
		i++;
	}
	*(*arr + i) = '\0';
	return (i);
}

static char	**ft_split_null(char **arr, int k)
{
	*(arr + k) = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	char	**arr;

	if (s == NULL)
		return (NULL);
	arr = ft_split_arr((char *)s, c);
	if (arr == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			i++;
		else
		{
			i += ft_split_store(arr + k, s + i, c);
			if (*(arr + k) == NULL)
				return (NULL);
			k++;
		}
	}
	return (ft_split_null(arr, k));
}
