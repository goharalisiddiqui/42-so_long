/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:52:12 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/19 23:22:14 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

static void	ft_buildelem(t_game *game, int i, int j)
{
	char	id;
	void	*elem;
	
	id = game->map.grid[j][i];
	if (id == '1')
		elem = game->wall;
	else if (id == 'C')
		elem = game->gem;
	else if (id == 'E')
		elem = game->exit;
	else if (id == 'P')
	{
		game->player_pos.x = i;
		game->player_pos.y = j;
		elem = game->pl_r;
	}
	else
		return;
	mlx_put_image_to_window(game->mlx, game->window,
			 elem, (game->blocks[j][i]).x, (game->blocks[j][i]).y);	
}

void	ft_buildworld(t_game *game)
{
	int	i;
	int	j;
	
	j = 0;
	while (j < game->map.height)
	{
		i = 0;
		while (i < game->map.width)
		{
			ft_buildelem(game, i, j);
			i++;
		}
		j++;
	}
}
