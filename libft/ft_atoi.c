/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 12:46:01 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/06/21 18:15:05 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_digits(char *str)
{
	int	digits;

	digits = 0;
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		digits *= 10;
		digits += *str - '0';
		str++;
	}
	return (digits);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	digits;

	sign = 1;
	digits = 0;
	while (((*str >= 9 && *str <= 13) || *str == ' ') && *str != '\0')
		str++;
	if ((*str == '-' || *str == '+') && *str != '\0')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if ((sign == -1) && (ft_strncmp(str, "2147483648", 11) == 0))
		return (-2147483648);
	digits = ft_atoi_digits(str);
	if (digits < 0)
	{
		if (sign == 1)
			return (-1);
		return (0);
	}
	return (digits * sign);
}
