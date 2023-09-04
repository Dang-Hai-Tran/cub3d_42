/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_minimap_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:50:56 by datran            #+#    #+#             */
/*   Updated: 2023/09/04 15:13:50 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_minimap_tile_par_pixels(t_minimap *minimap, int tile_x, int tile_y, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < minimap->tile_size)
	{
		j = 0;
		while (j < minimap->tile_size)
		{
			set_image_pixel(minimap->image, tile_x + j, tile_y + i, color);
			j++;
		}
		i++;
	}
}

static void	draw_minimap_tile(t_minimap *minimap, int mmap_x, int mmap_y)
{
	int		tile_size;
	int		dp_x;
	int		dp_y;

	tile_size = minimap->tile_size;
	dp_x = mmap_x * tile_size + MINIMAP_DISPLAY_BORDER;
	dp_y = mmap_y * tile_size + MINIMAP_DISPLAY_BORDER;
	if (minimap->map[mmap_y][mmap_x] == 'P')
		draw_minimap_tile_par_pixels(minimap, dp_x, dp_y, minimap->hex_player);
	else if (minimap->map[mmap_y][mmap_x] == '0')
		draw_minimap_tile_par_pixels(minimap, dp_x, dp_y, minimap->hex_floor);
	else if (minimap->map[mmap_y][mmap_x] == '1')
		draw_minimap_tile_par_pixels(minimap, dp_x, dp_y, minimap->hex_wall);
	else if (minimap->map[mmap_y][mmap_x] == ' ')
		draw_minimap_tile_par_pixels(minimap, dp_x, dp_y, minimap->hex_space);
}

static void	draw_minimap_border(t_minimap *minimap, int color)
{
	int		size;
	int		x;
	int		y;

	size = MINIMAP_DISPLAY_SIZE + 2 * MINIMAP_DISPLAY_BORDER;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (x < MINIMAP_DISPLAY_BORDER || x > size - MINIMAP_DISPLAY_BORDER || y < MINIMAP_DISPLAY_BORDER || y > size - MINIMAP_DISPLAY_BORDER)
				set_image_pixel(minimap->image, x, y, color);
			x++;
		}
		y++;
	}
}

static void	draw_minimap_image(t_minimap *minimap)
{
	int		x;
	int		y;

	y = 0;
	while (y < minimap->size)
	{
		x = 0;
		while (x < minimap->size)
		{
			if (!minimap->map[y] || !minimap->map[y][x] || minimap->map[y][x] == 0)
				break ;
			draw_minimap_tile(minimap, x, y);
			x++;
		}
		y++;
	}
	draw_minimap_border(minimap, minimap->hex_border);
}

void	render_minimap_image(t_minimap *minimap, t_display *dp)
{
	int		img_size;

	img_size = MINIMAP_DISPLAY_SIZE + 2 * MINIMAP_DISPLAY_BORDER;
	init_img(dp, minimap->image, img_size, img_size);
	draw_minimap_image(minimap);
	mlx_put_image_to_window(dp->mlx, dp->win, minimap->image->img, 10, 10);
	mlx_destroy_image(dp->mlx, minimap->image->img);
}
