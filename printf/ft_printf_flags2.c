/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 12:39:12 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/07 11:54:14 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_printf_flags_pi2(char *field, int prec)
{
	char	*str;
	int		size;
	int		i;

	size = ft_strlen(field);
	if (size < prec)
	{
		str = malloc((prec + 1) * sizeof(char));
		if (str == NULL)
			return (str);
		i = 0;
		while (i < (prec - size))
		{
			*(str + i) = '0';
			i++;
		}
		ft_memcpy(str + i, field, size);
		*(str + prec) = '\0';
		free(field);
		return (str);
	}
	else
		return (field);
}

char	*ft_printf_flags_pi(char *field, int prec)
{
	char	*str;
	char	*str2;

	if (prec == 0 && ft_memcmp(field, "0", 2) == 0)
	{
		free(field);
		return (ft_calloc(1, sizeof(char)));
	}
	if (*field == '-')
	{
		ft_memmove(field, field + 1, ft_strlen(field));
		str = ft_printf_flags_pi2(field, prec);
		str2 = ft_strjoin("-", str);
		free(str);
	}
	else
		str2 = ft_printf_flags_pi2(field, prec);
	return (str2);
}

char	*ft_printf_flags_ps(char *field, int prec)
{
	char	*str;

	if (ft_strlen(field) > prec)
	{
		str = malloc((prec + 1) * sizeof(char));
		if (str == NULL)
			return (str);
		ft_memcpy(str, field, prec);
		*(str + prec) = '\0';
		free(field);
		return (str);
	}
	else
		return (field);
}

char	*ft_printf_flags_arg(char **ptr, int i, va_list *arglst)
{
	char	*str;
	int		ind;
	int		size;
	char	*buff;

	ind = 0;
	size = ft_printf_flags_argn(ptr, i, arglst);
	str = malloc((size + 1) * sizeof(char));
	while (ind < size)
	{
		if (**ptr == '*')
		{
			buff = ft_itoa(va_arg(*arglst, int));
			ft_memcpy(str + ind, buff, ft_strlen(buff));
			ind += (ft_strlen(buff) - 1);
			free(buff);
		}
		else
			*(str + ind) = **ptr;
		ind++;
		(*ptr)++;
	}
	*(str + ind) = '\0';
	return (str);
}

char	*ft_printf_flags_mfw(char *field, int mfw, int laf, int zpf)
{
	char	*str;
	char	padchr;

	if (ft_strlen(field) >= mfw)
		return (field);
	padchr = ' ';
	if (zpf == 1 && laf == 0)
		padchr = '0';
	str = malloc((mfw + 1) * sizeof(char));
	if (str == NULL)
		return (str);
	if (laf == 0)
	{
		ft_memset(str, padchr, mfw - ft_strlen(field));
		ft_memcpy(str + mfw - ft_strlen(field), field, ft_strlen(field));
	}
	else
	{
		ft_memcpy(str, field, ft_strlen(field));
		ft_memset(str + ft_strlen(field), padchr, mfw - ft_strlen(field));
	}
	*(str + mfw) = '\0';
	free(field);
	return (str);
}
