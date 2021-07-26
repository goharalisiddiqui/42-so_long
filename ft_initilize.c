/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initilize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:51:49 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/26 20:45:32 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

static void	ft_initilizeblocks(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	game->blocks = malloc(game->map.height * (sizeof(t_point *)));
	while (j < game->map.height)
	{
		i = 0;
		game->blocks[j] = malloc(game->map.width * sizeof(t_point));
		while (i < game->map.width)
		{
			(game->blocks[j][i]).x = ft_fround(i, game->measures.x,
					 game->map.width);
			(game->blocks[j][i]).y = ft_fround(j, game->measures.y,
					 game->map.height);
			i++;
		}
		j++;
	}
}

static void	ft_setwindow(t_game *game, char *bg_path)
{
	t_point	*vals;

	vals = &(game->measures);
	game->bg.img = mlx_xpm_file_to_image(game->mlx, bg_path,
			 &(vals->x), &(vals->y));
	game->bg.addr = mlx_get_data_addr(game->bg.img, &(game->bg.bits_per_pixel),
			 &(game->bg.line_length), &(game->bg.endian));
	game->window = mlx_new_window(game->mlx, vals->x, vals->y, "so_long");
	mlx_put_image_to_window(game->mlx, game->window, game->bg.img, 0, 0);
}

void	ft_initialize(t_game *game, int fd)
{
	ft_readmap(&game->map, fd);
	ft_checkmap(&game->map);
	game->mlx = mlx_init();
	ft_setwindow(game, "./imgs/background.xpm");
	ft_initilizeblocks(game);
	ft_createimg(game, "./imgs/walls.xpm", &(game->wall));
	ft_createimg(game, "./imgs/gem.xpm", &(game->gem));
	ft_createimg(game, "./imgs/doorclosed.xpm", &(game->exit));
	ft_createimg(game, "./imgs/player_r.xpm", &(game->pl_r));
	ft_createimg(game, "./imgs/player_l.xpm", &(game->pl_l));
	ft_createimg(game, "./imgs/player_u.xpm", &(game->pl_u));
	ft_createimg(game, "./imgs/player_d.xpm", &(game->pl_d));
	ft_initnums(game, "./imgs/nums.xpm", &(game->nums));
	ft_buildworld(game);
}
