/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:07:49 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/01 17:45:18 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_printf_spec_qm(void)
{
	char	*str;

	str = malloc(2 * sizeof(char));
	if (str == NULL)
		return (NULL);
	*str = '%';
	*(str + 1) = '\0';
	return (str);
}

char	*ft_printf_spec_x(unsigned int field, char ident)
{
	char			*convstr;
	int				numchr;
	unsigned long	i;
	char			*str;
	int				a;

	if (ident == 'x')
		convstr = "0123456789abcdef";
	else
		convstr = "0123456789ABCDEF";
	numchr = ft_printf_specx_num((unsigned long)field, &i);
	str = malloc((numchr + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	a = 0;
	while (a < numchr)
	{
		*(str + a) = *(convstr + (field / i));
		field %= i;
		i /= 16;
		a++;
	}
	*(str + a) = '\0';
	return (str);
}

char	*ft_printf_spec_p(void *f, const char *convstr)
{
	int				numchr;
	unsigned long	i;
	char			*str;
	int				a;
	unsigned long	field;

	field = (unsigned long)f;
	numchr = ft_printf_specx_num(field, &i) + 2;
	str = malloc((numchr + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	*(str) = '0';
	*(str + 1) = 'x';
	a = 2;
	while (a < numchr)
	{
		*(str + a) = convstr[(field / i)];
		field %= i;
		i /= 16;
		a++;
	}
	*(str + a) = '\0';
	return (str);
}
