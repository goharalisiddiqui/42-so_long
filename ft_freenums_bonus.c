/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freenums_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:49:42 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/27 21:03:59 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

void	ft_freenums(t_game *game)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		mlx_destroy_image(game->mlx, game->nums.digits[i]);
		i++;
	}
}
