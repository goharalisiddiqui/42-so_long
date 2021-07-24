/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:28:43 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/24 20:03:59 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

static void	ft_lsterr(t_list **lst, int fd, char *str)
{
	ft_lstclear(lst, free);
	if (fd > 1)
		close(fd);
	ft_err(str);
}

static void	ft_savemap(t_map *map, t_list **buff, int height)
{
	int		ind;
	t_list	*elem;

	ind = 0;
	elem = *buff;
	map->grid = malloc(height * sizeof(char *));
	if (map->grid == NULL)
		ft_lsterr(buff, 1, "Malloc failed");
	while (ind < height)
	{
		(map->grid)[ind] = ft_strdup(elem->content);
		ind++;
		elem = elem->next;
	}
	ft_lstclear(buff, free);
}

void	ft_readmap(t_map *map, int fd)
{
	char	*line;
	t_list	*vault;
	int		flag;

	flag = 1;
	vault = NULL;
	map->width = 0;
	map->height = 0;
	while (flag == 1)
	{
		flag = get_next_line(fd, &line);
		if (flag == -1)
			ft_lsterr(&vault, fd, "Error reading input file");
		if (map->width && ft_strlen(line) != map->width)
			ft_lsterr(&vault, fd, "Non-rectangular map input");
		if (ft_strlen(line) == 0)
			ft_lsterr(&vault, fd, "Empty line in input file");
		map->width = ft_strlen(line);
		map->height = map->height + 1;
		ft_lstadd_back(&vault, ft_lstnew(line));
	}
	close(fd);
	ft_savemap(map, &vault, map->height);
}
