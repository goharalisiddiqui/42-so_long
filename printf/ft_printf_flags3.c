/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:47:01 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/01 17:42:56 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_printf_flags_p(char *field, char *flags)
{
	char	*ptr;
	int		mfw;
	int		laf;
	int		zpf;	

	ptr = ft_strchr(flags, '.');
	if (ptr != NULL && ft_isdigit(*(ptr + 1)))
		field = ft_printf_flags_pi(field, ft_atoi(ptr + 1));
	if (ptr != NULL && *(ptr + 1) == '\0' && ft_memcmp(field, "0x0", 4) == 0)
		*(field + 2) = '\0';
	mfw = ft_printf_mfwcalc(flags, &laf, &zpf);
	if (mfw <= ft_strlen(field))
		return (field);
	if (*field == '-' && zpf == 1)
	{
		ptr = ft_printf_flags_mfw(ft_substr(field, 1, mfw), mfw - 1, laf, zpf);
		free(field);
		field = ft_strjoin("-", ptr);
		free(ptr);
		return (field);
	}
	return (ft_printf_flags_mfw(field, mfw, laf, zpf));
}
