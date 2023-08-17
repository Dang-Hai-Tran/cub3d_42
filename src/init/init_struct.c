/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:17:12 by codespace         #+#    #+#             */
/*   Updated: 2023/08/17 00:48:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map_struct(t_map *map)
{
	map->fd = 0;
	map->filename = 0;
	map->rows = 0;
	map->cols = 0;
	map->pos = 0;
	map->exists = 0;
}

void	init_textureinfo_struct(t_textureinfo *textureInfo)
{
	textureInfo->north = 0;
	textureInfo->south = 0;
	textureInfo->west = 0;
	textureInfo->east = 0;
	textureInfo->floor_rgb = 0;
	textureInfo->ceiling_rgb = 0;
	textureInfo->size = 0;
	textureInfo->index = 0;
	textureInfo->step = 0;
	textureInfo->pos = 0;
	textureInfo->x = 0;
	textureInfo->y = 0;
}

void	init_player_struct(t_player *player)
{
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->has_moved = 0;
	player->move_x = 0;
	player->move_x = 0;
	player->rotate = 0;
}

void	init_img_zero_struct(t_img *image)
{
	image->img = 0;
	image->addr = 0;
	image->pixel_bits = 0;
	image->size_line = 0;
	image->endian = 0;
}

void	init_display_struct(t_display *display)
{
	display->mlx = 0;
	display->win = 0;
	display->win_height = 0;
	display->win_width = 0;
	display->map = malloc(sizeof(t_map));
	init_map_struct(display->map);
	display->player = malloc(sizeof(t_player));
	init_player_struct(display->player);
	display->ray = 0;
	display->textureInfo = malloc(sizeof(t_textureinfo));
	init_textureinfo_struct(display->textureInfo);
	display->map_arr_str = 0;
	display->textures = 0;
	display->textures_pixels = 0;
}

void	init_struct(t_display *display, char *filename)
{
	char	*res;

	init_display_struct(display);
	init_map_struct(display->map);
	res = ft_strstr(filename, ".cub");
	if (ft_strlen(res) == 4)
	{
		init_map(display, filename);
		// init_gamewindow(display);
		// init_img_struct(display);
		//init_texture_struct(display);
		// check_textures(display);
	}
	else
		ft_error_fd("Incorrect map extension use .cub\n", 1, display);
}
