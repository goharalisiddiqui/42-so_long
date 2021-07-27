/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:53:10 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/02 18:06:10 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_printf_spec_di(int field)
{
	return (ft_itoa(field));
}

static char	*ft_printf_spec_u(unsigned int field)
{
	char	*extra;
	char	*subresult;
	char	*comb;

	if (field > 2147483647)
	{
		extra = malloc(2 * sizeof(char));
		*extra = (char)((field % 10) + 48);
		*(extra + 1) = '\0';
		field /= 10;
		subresult = ft_itoa(field);
		comb = ft_strjoin(subresult, extra);
		free(subresult);
		free(extra);
		return (comb);
	}
	return (ft_itoa(field));
}

static char	*ft_printf_spec_s(const char *field, char *flags)
{
	char	*str;

	str = ft_strchr(flags, '.');
	if (field == NULL)
		field = "(null)";
	if (str != NULL)
		return (ft_substr(field, 0, ft_atoi(str + 1)));
	else
		return (ft_strdup(field));
}

char	*ft_printf_spec_c(int field)
{
	return (ft_itoa(field));
}

char	*ft_printf_spec(va_list *arglst, char ident, char *flags)
{
	if (ident == 'd' || ident == 'i')
		return (ft_printf_spec_di(va_arg(*arglst, int)));
	else if (ident == '%')
		return (ft_printf_spec_qm());
	else if (ident == 'u')
		return (ft_printf_spec_u(va_arg(*arglst, unsigned int)));
	else if (ident == 'c')
		return (ft_printf_spec_c(va_arg(*arglst, int)));
	else if (ident == 's')
		return (ft_printf_spec_s(va_arg(*arglst, const char *), flags));
	else if (ident == 'X' || ident == 'x')
		return (ft_printf_spec_x(va_arg(*arglst, unsigned int), ident));
	else if (ident == 'p')
		return (ft_printf_spec_p(va_arg(*arglst, void *), "0123456789abcdef"));
	else
		return (NULL);
}
