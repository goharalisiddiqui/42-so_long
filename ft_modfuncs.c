/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modfuncs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:28:54 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/24 20:02:36 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

static unsigned int	ft_getbg(t_img wall, t_point iter, t_point block)
{
	t_point	pos;
	char	*dst;

	pos.x = iter.x + block.x;
	pos.y = iter.y + block.y;
	dst = wall.addr + (pos.y * wall.line_length
			 + pos.x * (wall.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	ft_clearblock(t_game *game, t_point block)
{
	t_img	bg;
	t_point	bg_size;
	t_point	iter;

	bg_size.x = game->measures.x / game->map.width;
	bg_size.y = game->measures.y / game->map.height;
	bg.img = mlx_new_image(game->mlx, bg_size.x, bg_size.y);
	bg.addr = mlx_get_data_addr(bg.img, &(bg.bits_per_pixel),
			 &(bg.line_length), &(bg.endian));
	iter.x = 0;
	iter.y = 0;
	while (iter.x < bg_size.x)
	{
		iter.y = 0;
		while (iter.y < bg_size.y)
		{	
			ft_mlx_pixel_put(&bg, iter.x, iter.y,
				 ft_getbg(game->bg, iter, block));
			iter.y = iter.y + 1;
		}
		iter.x = iter.x + 1;
	}
	mlx_put_image_to_window(game->mlx, game->window, bg.img, block.x, block.y);
	mlx_destroy_image(game->mlx, bg.img);
}

void	ft_opendoor(t_game *game)
{
	t_point	iter;

	mlx_destroy_image(game->mlx, game->exit);
	ft_createimg(game, "./imgs/dooropen.png", &(game->exit));
	iter.x = 0;
	iter.y = 0;
	while (iter.y < game->map.height)
	{
		iter.x = 0;
		while (iter.x < game->map.width)
		{
			if (game->map.grid[iter.y][iter.x] == 'E')
			{
				ft_clearblock(game,
					 game->blocks[iter.y][iter.x]);
				mlx_put_image_to_window(game->mlx, game->window, game->exit,
					 (game->blocks[iter.y][iter.x]).x,
					 	 (game->blocks[iter.y][iter.x]).y);
			}
			iter.x = iter.x + 1;
		}
		iter.y = iter.y + 1;
	}
}

static void	ft_moveplayer(t_game *game, int x, int y, void *player)
{
	ft_clearblock(game, game->blocks[game->player_pos.y][game->player_pos.x]);
	if (game->map.grid[game->player_pos.y][game->player_pos.x] != 'E')
		game->map.grid[game->player_pos.y][game->player_pos.x] = '0';
	else
		mlx_put_image_to_window(game->mlx, game->window, game->exit,
			 (game->blocks[game->player_pos.y][game->player_pos.x]).x,
			 	 (game->blocks[game->player_pos.y][game->player_pos.x]).y);
	game->player_pos.x = x;
	game->player_pos.y = y;
	if (game->map.grid[y][x] == 'C')
	{
		ft_clearblock(game, game->blocks[y][x]);
		ft_tryfinish(game, ft_opendoor, 1);
	}
	if (game->map.grid[y][x] == 'E')
		ft_tryfinish(game, ft_endgame, 0);
	else
		game->map.grid[y][x] = 'P';
	mlx_put_image_to_window(game->mlx, game->window, player,
		 (game->blocks[y][x]).x, (game->blocks[y][x]).y);
	game->moves++;
	ft_showscore(game);
}

void	ft_movekeys(t_game *game, int keycode)
{
	char	**grid;
	int		x;
	int		y;

	grid = game->map.grid;
	y = game->player_pos.y;
	x = game->player_pos.x;
	if (keycode == 13 && grid[y - 1][x] != '1')
		ft_moveplayer(game, x, y - 1, game->pl_u);
	else if (keycode == 1 && grid[y + 1][x] != '1')
		ft_moveplayer(game, x, y + 1, game->pl_d);
	else if (keycode == 0 && grid[y][x - 1] != '1')
		ft_moveplayer(game, x - 1, y, game->pl_l);
	else if (keycode == 2 && grid[y][x + 1] != '1')
		ft_moveplayer(game, x + 1, y, game->pl_r);
}
