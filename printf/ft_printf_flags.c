/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:13:15 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/02 18:28:39 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_printf_flags_diuxx(char *field, char *flags)
{
	char	*ptr;
	int		mfw;
	int		laf;
	int		zpf;	

	ptr = ft_strchr(flags, '.');
	if (ptr != NULL && ft_isdigit(*(ptr + 1)))
		field = ft_printf_flags_pi(field, ft_atoi(ptr + 1));
	if (ptr != NULL && *(ptr + 1) == '\0')
		field = ft_printf_flags_pi(field, 0);
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

static char	*ft_printf_flags_s(char *field, char *flags)
{
	int		mfw;
	int		laf;
	int		zpf;	

	mfw = ft_printf_mfwcalc(flags, &laf, &zpf);
	return (ft_printf_flags_mfw(field, mfw, laf, zpf));
}

static char	*ft_printf_flags_c(char *field, char *flags)
{
	int		mfw;
	int		laf;
	int		zpf;	

	mfw = ft_printf_mfwcalc(flags, &laf, &zpf);
	mfw += (ft_strlen(field) - 1);
	if (mfw <= ft_strlen(field))
		return (field);
	return (ft_printf_flags_mfw(field, mfw, laf, 0));
}

static char	*ft_printf_flags_qm(char *field, char *flags)
{
	int		mfw;
	int		laf;
	int		zpf;	

	mfw = ft_printf_mfwcalc_qm(flags, &laf, &zpf);
	return (ft_printf_flags_mfw(field, mfw, laf, zpf));
}

char	*ft_printf_flags(char *field, char *flags, char ident)
{
	if (ft_strchr("diuxX", ident) != NULL)
		return (ft_printf_flags_diuxx(field, flags));
	else if (ident == 's')
		return (ft_printf_flags_s(field, flags));
	else if (ident == 'p')
		return (ft_printf_flags_p(field, flags));
	else if (ident == 'c')
		return (ft_printf_flags_c(field, flags));
	else if (ident == '%')
		return (ft_printf_flags_qm(field, flags));
	else
		return (NULL);
}
