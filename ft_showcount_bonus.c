/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_showcount_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 18:58:46 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/27 21:19:53 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

static unsigned int	ft_getdigpixel(t_img img, t_point iter, int x, int y)
{
	char	*dst;
	t_point	pos;

	pos.x = iter.x + x;
	pos.y = iter.y + y;
	dst = img.addr + (pos.y * img.line_length
			 + pos.x * (img.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

static void	*ft_getnumimg(t_game *game, t_img fullimg, int x, int y)
{
	t_img	img;
	t_point	iter;

	iter.x = 0;
	iter.y = 0;
	img.img = mlx_new_image(game->mlx, game->nums.w, game->nums.h);
	img.addr = mlx_get_data_addr(img.img,
			 &img.bits_per_pixel, &img.line_length, &img.endian);
	while (iter.y < game->nums.h)
	{
		iter.x = 0;
		while (iter.x < game->nums.w)
		{
			ft_mlx_pixel_put(&img, iter.x, iter.y,
				 ft_getdigpixel(fullimg, iter, x, y));
			iter.x = iter.x + 1;
		}
		iter.y = iter.y + 1;
	}
	return (img.img);
}

t_img	ft_checkcsize(t_game *game, t_img img_o, t_point *size_o)
{
	t_img	img_m;
	t_point	size_m;

	if ((size_o->y) / 2 <= game->blocks[1][1].y)
		return (img_o);
	size_m.y = 2 * (game->blocks[1][1].y);
	size_m.x = ft_fround(size_o->x, size_m.y, size_o->y);
	img_m.img = mlx_new_image(game->mlx, size_m.x, size_m.y);
	img_m.addr = mlx_get_data_addr(img_m.img, &img_m.bits_per_pixel,
			 &img_m.line_length, &img_m.endian);
	ft_resize(img_o, *size_o, &img_m, size_m);
	mlx_destroy_image(game->mlx, img_o.img);
	*size_o = size_m;
	return (img_m);
}

void	ft_initnums(t_game *game, char *path, t_nums *nums)
{
	t_point	size;
	t_img	img;
	int		ind;

	img.img = mlx_xpm_file_to_image(game->mlx, path, &size.x, &size.y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			 &img.line_length, &img.endian);
	img = ft_checkcsize(game, img, &size);
	nums->h = size.y / 2;
	nums->w = size.x / 5;
	nums->digits = malloc(10 * sizeof(void *));
	ind = 0;
	while (ind < 10)
	{
		nums->digits[ind] = ft_getnumimg(game, img,
				 (ind % 5) * nums->w, (ind / 5) * nums->h);
		ind++;
	}
	mlx_destroy_image(game->mlx, img.img);
}

void	ft_showscore(t_game *game)
{
	char	*score;
	int		len;
	int		x_loc;
	int		dig;

	x_loc = 0;
	score = ft_itoa(game->moves);
	len = ft_strlen(score);
	while (*score)
	{
		dig = *score - 48;
		mlx_put_image_to_window(game->mlx, game->window,
			 game->nums.digits[dig], x_loc, 0);
		x_loc += game->nums.w;
		score++;
	}
	score -= len;
	free(score);
}
