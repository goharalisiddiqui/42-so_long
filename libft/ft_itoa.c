/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:49:06 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/06/25 17:08:46 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_numfinder(int *n, int *i)
{
	int	numchr;
	int	a;

	numchr = 0;
	*i = 1;
	if (*n < 0)
	{
		numchr++;
		if (*n == -2147483648)
			(*n)++;
		(*n) *= -1;
	}
	a = *n;
	while (a > 9)
	{
		numchr++;
		a /= 10;
		(*i) *= 10;
	}
	numchr++;
	return (numchr);
}

static int	ft_itoa_store(char *str, int numchr, int n, int i)
{
	int	a;

	a = 0;
	while (a < numchr)
	{
		*(str + a) = (char)((n / i) + 48);
		n %= i;
		i /= 10;
		a++;
	}
	*(str + a) = '\0';
	return (a);
}

char	*ft_itoa(int n)
{
	int		numchr;
	int		i;
	char	*str;
	int		num;

	num = n;
	numchr = ft_itoa_numfinder(&n, &i);
	str = malloc((numchr + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (num < 0)
	{
		*str = '-';
		i = ft_itoa_store(str + 1, numchr - 1, n, i);
		if (num == -2147483648)
			*(str + i) = '8';
	}
	else
		i = ft_itoa_store(str, numchr, n, i);
	return (str);
}
