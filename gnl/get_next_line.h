/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:45:42 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/15 13:13:24 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_vlist
{
	int				idt;
	char			*content;
	struct s_vlist	*next;
}	t_vlist;

int		get_next_line(int fd, char **line);
void	ft_vlstadd(t_vlist **lst, int id, char *str);
t_vlist	*ft_vlstlocdel(t_vlist **lst, int fd, int ident);

#endif