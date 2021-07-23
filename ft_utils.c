/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:28:56 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/19 23:21:54 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

void	ft_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void ft_endgame(t_game *game)
{
	int	i;
	
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->gem);
	mlx_destroy_image(game->mlx, game->pl_r);
	mlx_destroy_image(game->mlx, game->pl_l);
	mlx_destroy_image(game->mlx, game->pl_u);
	mlx_destroy_image(game->mlx, game->pl_d);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->bg.img);
	i = 0;
	while (i < game->map.height)
	{
		free(game->map.grid[i]);
		free(game->blocks[i]);
		i++;
	}
	free(game->map.grid);
	free(game->blocks);
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
}

void ft_tryfinish(t_game *game, void (*f)(t_game *), int val)
{
	t_point iter;
	int colls;

	iter.x = 0;
	iter.y = 0;
	colls = 0;
	while (iter.y < game->map.height)
	{
		iter.x = 0;
		while (iter.x < game->map.width)
		{
			
			if (game->map.grid[iter.y][iter.x] == 'C')
				colls++;
			iter.x = iter.x + 1;
		}
		iter.y = iter.y + 1;
	}
	if (colls == val)
		f(game);
}