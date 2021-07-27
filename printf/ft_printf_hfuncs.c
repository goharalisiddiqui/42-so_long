/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hfuncs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:02:41 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/27 18:14:52 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printf_putstr(void *cont, char ident)
{
	char	*str;

	if (ident == 'c')
	{
		str = (char *)cont;
		while (*str)
		{
			if (*str == ' ')
			{
				ft_putchar_fd(' ', 1);
				str++;
			}
			else
			{
				ft_putchar_fd(ft_atoi(str), 1);
				while (*str != ' ' && *str != '\0')
					str++;
			}	
		}
	}
	else
		ft_putstr_fd((char *)cont, 1);
}

int	ft_printf_out(t_plist *strlst)
{
	int		count;
	t_plist	*elem;

	elem = strlst;
	count = 0;
	while (elem != NULL)
	{
		if ((*elem).ident == 'c')
			count += ft_chrlen((*elem).content);
		else
			count += ft_strlen((*elem).content);
		elem = (*elem).next;
	}
	ft_plstiter(strlst, ft_printf_putstr);
	ft_plstclear(&strlst, free);
	return (count);
}

int	ft_printf_specx_num(unsigned long n, unsigned long *i)
{
	int	numchr;

	numchr = 0;
	*i = 1;
	while (n > 15)
	{
		numchr++;
		n /= 16;
		(*i) *= 16;
	}
	numchr++;
	return (numchr);
}

int	ft_printf_flags_argn(char **ptr, int i, va_list *arglst)
{
	int		size;
	int		ind;
	va_list	arglst_copy;
	char	*str;

	size = i;
	ind = 0;
	va_copy(arglst_copy, *arglst);
	while (ind < i)
	{
		if (*(*ptr + ind) == '*')
		{
			str = ft_itoa(va_arg(arglst_copy, int));
			size += (ft_strlen(str) - 1);
			free(str);
		}
		ind++;
	}
	va_end(arglst_copy);
	return (size);
}

int	ft_printf_mfwcalc(char *flags, int *laf, int *zpf)
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
		{
			if (ptr == NULL || *(ptr + 1) == '-')
				*zpf = 1;
		}
		else if (ft_isdigit(*flags))
			return (ft_atoi(flags));
		flags++;
	}
	return (0);
}
