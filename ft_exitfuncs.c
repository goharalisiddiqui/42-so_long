/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exitfuncs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:52:20 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/19 13:52:36 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

void	ft_err(char *errstr)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(errstr, 2);
	exit(EXIT_FAILURE);
}

void	ft_freemap(t_map *map)
{
	int	j;

	j = 0;
	while (j < map->height)
	{
		free(map->grid[j]);
		j++;
	}
}
