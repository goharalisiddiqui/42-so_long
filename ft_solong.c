/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:21:48 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/19 23:03:23 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

int ft_keyhook(int keycode, t_game *game)
{
	if ((keycode >= 0 && keycode <= 2) || keycode == 13)
		ft_movekeys(game, keycode);
	else if (keycode == 53)
		ft_endgame(game);
	return (1);
}


int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;
	
	fd = ft_checkinput(argc, argv);
	ft_initialize(&game, fd);
	game.moves = 0;
	mlx_hook(game.window, 2, 1L<<0, ft_keyhook, &game);
	mlx_loop(game.mlx);
}
