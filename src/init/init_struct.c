/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:17:12 by codespace         #+#    #+#             */
/*   Updated: 2023/08/20 11:59:39 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mapinfo(t_mapinfo *mapinfo)
{
	mapinfo->fd = 0;
	mapinfo->path = NULL;
	mapinfo->rows = 0;
	mapinfo->cols = 0;
	// mapinfo->pos = 0;
	// mapinfo->exists = 0;
}

void	init_textureinfo(t_texinfo *texinfo)
{
	texinfo->north = 0;
	texinfo->south = 0;
	texinfo->west = 0;
	texinfo->east = 0;
	texinfo->hex_ceiling = 0;
	texinfo->hex_floor = 0;
	texinfo->size = 0;
	texinfo->index = 0;
	texinfo->step = 0;
	texinfo->pos = 0;
	texinfo->x = 0;
	texinfo->y = 0;
}

void	init_player(t_player *player)
{
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->has_moved = 0;
	player->move_x = 0;
	player->move_x = 0;
	player->rotate = 0;
}

void	init_img_zero(t_img *image)
{
	image->img = 0;
	image->addr = 0;
	image->pixel_bits = 0;
	image->size_line = 0;
	image->endian = 0;
}

void	init_display(t_display *display)
{
	display->mlx = 0;
	display->win = 0;
	display->win_height = 0;
	display->win_width = 0;
	display->map = malloc(sizeof(t_mapinfo));
	init_mapinfo_struct(display->map);
	display->player = malloc(sizeof(t_player));
	init_player_struct(display->player);
	display->ray = 0;
	display->texinfo = malloc(sizeof(t_texinfo));
	init_texinfo_struct(display->texinfo);
	display->map = NULL;
	display->textures = NULL;
	display->textures_pixels = NULL;
}

void	init_struct(t_display *display, char *path)
{
	char	*res;

	init_display(display);
	res = ft_strstr(path, ".cub");
	if (ft_strlen(res) == 4)
		init_map(display, path);
	else
		free_exit(display, err_msg("Incorrect map extension .cub", 1));
}
