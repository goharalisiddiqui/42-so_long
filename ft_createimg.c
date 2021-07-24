/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createimg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:47:47 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/07/24 19:50:43 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

int	ft_fround(int mul, int num, int den)
{
	float	f;

	f = (float)mul;
	f = f * num;
	f = f / den;
	if (f - (int)f > 0.5)
		return ((int)(f + 1));
	return ((int)f);
}

static unsigned int	ft_getpixel(t_img wall, t_point iter,
	 t_point block_size, t_point img_size)
{
	t_point	pos;
	char	*dst;

	pos.x = ft_fround(iter.x, img_size.x, block_size.x);
	pos.y = ft_fround(iter.y, img_size.y, block_size.y);
	dst = wall.addr + (pos.y * wall.line_length + pos.x
			 * (wall.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	ft_resize(t_img img_o, t_point img_o_size,
	 t_img *img_m, t_point img_m_size)
{
	t_point	iter;

	iter.x = 0;
	iter.y = 0;
	while (iter.x < img_m_size.x)
	{
		iter.y = 0;
		while (iter.y < img_m_size.y)
		{	
			ft_mlx_pixel_put(img_m, iter.x, iter.y,
				 ft_getpixel(img_o, iter, img_m_size, img_o_size));
			iter.y = iter.y + 1;
		}
		iter.x = iter.x + 1;
	}
}

void	ft_createimg(t_game *game, char *path, void **img)
{
	t_img	img_m;
	t_point	img_m_size;
	t_img	img_o;
	t_point	img_o_size;

	img_m_size.x = game->measures.x / game->map.width;
	img_m_size.y = game->measures.y / game->map.height;
	img_o.img = mlx_png_file_to_image(game->mlx, path,
			 &(img_o_size.x), &(img_o_size.y));
	img_o.addr = mlx_get_data_addr(img_o.img, &img_o.bits_per_pixel,
			 &img_o.line_length, &img_o.endian);
	img_m.img = mlx_new_image(game->mlx, img_m_size.x, img_m_size.y);
	img_m.addr = mlx_get_data_addr(img_m.img, &img_m.bits_per_pixel,
			 &img_m.line_length, &img_m.endian);
	ft_resize(img_o, img_o_size, &img_m, img_m_size);
	*img = img_m.img;
	mlx_destroy_image(game->mlx, img_o.img);
}
