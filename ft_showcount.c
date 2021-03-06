/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_showcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 18:58:46 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/27 21:03:40 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"
#include "./printf/libftprintf.h"

void	ft_freenums(t_game *game)
{
	int	i;

	i = game->moves;
	return ;
}

void	ft_initnums(t_game *game, char *path, t_nums *nums)
{
	int	i;

	i = game->moves;
	i = nums->h;
	i = (int)*path;
	return ;
}

void	ft_showscore(t_game *game)
{
	ft_printf("Number of moves = %d\n", game->moves);
}
