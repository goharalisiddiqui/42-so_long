/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hfuncs2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:27:03 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/27 18:15:02 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_mfwcalc_qm(char *flags, int *laf, int *zpf)
{
	char	*ptr;

	*laf = 0;
	*zpf = 0;
	ptr = ft_strchr(flags, 46);
	while (*flags && (*flags != '.'))
	{
		if (*flags == '-')
			*laf = 1;
		else if (*flags == '0')
			*zpf = 1;
		else if (ft_isdigit(*flags))
			return (ft_atoi(flags));
		flags++;
	}
	return (0);
}

int	ft_chrlen(char *str)
{
	int	count;

	count = 1;
	while (*str)
	{
		if (*str == ' ')
			count++;
		str++;
	}
	return (count);
}
