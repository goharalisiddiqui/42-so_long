/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:53:20 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/27 18:11:43 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_plist
{
	void			*content;
	char			ident;
	struct s_plist	*next;
}	t_plist;

int		ft_printf(const char *format, ...);
int		ft_printf_specx_num(unsigned long n, unsigned long *i);
int		ft_printf_flags_argn(char **ptr, int i, va_list *arglst);
int		ft_printf_mfwcalc(char *flags, int *laf, int *zpf);
int		ft_printf_mfwcalc_qm(char *flags, int *laf, int *zpf);
int		ft_chrlen(char *str);
char	*ft_printf_spec(va_list *arglst, char ident, char *flags);
char	*ft_printf_spec_x(unsigned int field, char ident);
char	*ft_printf_spec_p(void *f, const char *convstr);
char	*ft_printf_spec_qm(void);
char	*ft_printf_flags_arg(char **ptr, int i, va_list *arglst);
char	*ft_printf_flags(char *field, char *flags, char ident);
char	*ft_printf_flags_pi(char *field, int prec);
char	*ft_printf_flags_ps(char *field, int prec);
char	*ft_printf_flags_mfw(char *field, int mfw, int laf, int zpf);
char	*ft_printf_flags_p(char *field, char *flags);
int		ft_printf_out(t_plist *strlst);
t_plist	*ft_plstnew(void *content, char ident);
void	ft_plstadd_back(t_plist **lst, t_plist *new);
void	ft_plstclear(t_plist **lst, void (*del)(void*));
void	ft_plstiter(t_plist *lst, void (*f)(void *, char));
t_plist	*ft_plstlast(t_plist *lst);

#endif