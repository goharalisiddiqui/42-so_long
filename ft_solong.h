/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solong.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:38:19 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/19 23:19:43 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SOLONG_H
# define FT_SOLONG_H
# include <stdio.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_point
{
	int x;
	int y;
}	t_point;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	
	void	*window;
	void	*wall;
	void	*gem;
	void	*exit;
	void	*pl_r;
	void	*pl_l;
	void	*pl_u;
	void	*pl_d;
	int		moves;
	t_img	bg;
	t_point	player_pos;
	t_point	measures;
	t_map	map;
	t_point	**blocks;
}	t_game;



void	ft_err(char *errstr);
int		ft_fround(int mul, int num, int den);
void	ft_freemap(t_map *map);
void	ft_initialize(t_game *game, int fd);
int		ft_checkinput(int argc, char **argv);
void	ft_checkmap(t_map *map);
void	ft_readmap(t_map *map, int fd);
void	ft_createimg(t_game *game, char *path, void **img);
void	ft_buildworld(t_game *game);
void	ft_clearblock(t_game *game, t_point block);
void	ft_mlx_pixel_put(t_img *data, int x, int y, int color);
void	ft_movekeys(t_game *game, int keycode);
void	ft_tryfinish(t_game *game, void (*f)(t_game *), int val);
void	ft_endgame(t_game *game);
void	ft_opendoor(t_game *game);

#endif