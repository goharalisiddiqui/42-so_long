/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 20:51:13 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/19 13:52:32 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

static void	ft_griderr(t_map *map, char *str)
{
	ft_freemap(map);
	ft_err(str);
}

static void	ft_checkgridpos(t_map *map, t_point iter, int *points)
{
	char c;
	
	c = map->grid[iter.y][iter.x];
	if (ft_strchr("01CEP", c) == NULL)
		ft_griderr(map, "Invalid character in map");
	if (c == 'E')
	{
		if (points[1] == 1)
			ft_griderr(map, "Too many exit positions in map");
		points[1] = 1;
	}
	if (c == 'P')
	{
		if (points[0] == 1)
			ft_griderr(map, "Too many entry positions in map");
		points[0] = 1;
	}
	if (c == 'C')
		points[2] = points[2] + 1;
}

static void	ft_checkgridsafety(t_map *map, t_point iter)
{
	int		at_boundary;
	char	**grid;

	grid  = map->grid;
	if (grid[iter.y][iter.x] == '1')
		return;
	at_boundary = 0;
	if (iter.y == 0 || iter.y == map->height - 1
		 || iter.x == 0 || grid[iter.y][iter.x + 1] == '\0')
		at_boundary = 1;
	if (at_boundary && grid[iter.y][iter.x] != '1')
		ft_griderr(map, "Map not surrounded by boundaries");
}

void	ft_checkmap(t_map *map)
{
	t_point	iter;
	int		points[] = {0, 0, 0};

	iter.y = 0;
	while (iter.y < map->height)
	{
		iter.x = 0;
		while (iter.x < map->width)
		{
			ft_checkgridpos(map, iter, points);
			ft_checkgridsafety(map, iter);
			iter.x = iter.x + 1;
		}
		iter.y = iter.y + 1;
	}
	if (points[2] == 0)
		ft_griderr(map, "Zero collectables on the map");
}

int	ft_checkinput(int argc, char **argv)
{
	int fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd >= 0)
			return (fd);
	}
	perror("Error in Opening File");
	exit(-1);
}
