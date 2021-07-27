/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:23:23 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/27 18:13:17 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_printf_conv(char **ptr, va_list *arglst, t_plist **strlst)
{
	static char	specs[] = "cspdiuxX%";
	int			i;
	char		*flags;
	char		*field;

	i = 0;
	while (ft_strchr(specs, *(*ptr + i)) == NULL)
	{
		if (*(*ptr + i) == '\0' || ft_isalpha(*(*ptr + i)))
			return (ft_isalpha(*(*ptr + i)));
		i++;
	}
	flags = ft_printf_flags_arg(ptr, i, arglst);
	field = ft_printf_spec(arglst, **ptr, flags);
	field = ft_printf_flags(field, flags, **ptr);
	free(flags);
	if (field == NULL)
		return (0);
	ft_plstadd_back(strlst, ft_plstnew(field, **ptr));
	(*ptr)++;
	return (1);
}

static int	ft_printf_nconv(char **ptr, t_plist **strlst)
{
	int		nchr;
	char	*str;

	nchr = 0;
	while ((*(*ptr + nchr) != '%') && *(*ptr + nchr))
		nchr++;
	str = malloc((nchr + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	ft_plstadd_back(strlst, ft_plstnew(str, 'z'));
	while (nchr > 0)
	{
		*str = **ptr;
		str++;
		(*ptr)++;
		nchr--;
	}
	*str = '\0';
	return (1);
}

int	ft_printf(const char *format, ...)
{
	t_plist	*strlst;
	va_list	arglst;
	char	*ptr;
	int		err_flag;

	va_start(arglst, format);
	strlst = NULL;
	ptr = (char *)format;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			err_flag = ft_printf_conv(&ptr, &arglst, &strlst);
		}
		else
			err_flag = ft_printf_nconv(&ptr, &strlst);
		if (err_flag == 0)
			return (-1);
	}
	va_end(arglst);
	return (ft_printf_out(strlst));
}
