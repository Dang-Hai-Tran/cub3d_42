/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:23:02 by datran            #+#    #+#             */
/*   Updated: 2023/08/23 09:18:57 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void init_mapinfo(t_mapinfo *mapinfo)
{
	mapinfo->fd = 0;
	mapinfo->nb_lines = 0;
	mapinfo->path = NULL;
	mapinfo->height = 0;
	mapinfo->width = 0;
	mapinfo->lines = NULL;
}

static void init_player_zero(t_player *player)
{
	player->dir = UNDEFINED;
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->has_moved = 0;
	player->move_x = 0;
	player->move_x = 0;
	player->rotate = 0;
}

void	init_texinfo(t_texinfo *texinfo)
{
	texinfo->north = NULL;
	texinfo->south = NULL;
	texinfo->east = NULL;
	texinfo->west = NULL;
	texinfo->rgb_floor = NULL;
	texinfo->rgb_ceiling = NULL;
	texinfo->hex_ceiling = 0;
	texinfo->hex_floor = 0;
	texinfo->size = TEX_SIZE;
	texinfo->step = 0;
	texinfo->pos = 0.0;
	texinfo->x = 0;
	texinfo->y = 0;
}

void	init_display(t_display *display)
{
	display->mlx = NULL;
	display->win = NULL;
	display->win_height = WIN_HEIGHT;
	display->win_width = WIN_WIDTH;
	display->player = ft_calloc(1, sizeof(t_player));
	if (!display->player)
		free_exit(display, err_msg("calloc player", 1));
	init_player_zero(display->player);
	display->mapinfo = ft_calloc(1, sizeof(t_mapinfo));
	if (!display->mapinfo)
		free_exit(display, err_msg("calloc mapinfo", 1));
	init_mapinfo(display->mapinfo);
	display->texinfo = ft_calloc(1, sizeof(t_texinfo));
	if (!display->texinfo)
		free_exit(display, err_msg("calloc texinfo", 1));
	init_texinfo(display->texinfo);
	display->ray = ft_calloc(1, sizeof(t_ray));
	if (!display->ray)
		free_exit(display, err_msg("calloc ray", 1));
	init_ray(display->ray);
	display->map = NULL;
	display->texpixels = NULL;
	display->texbuffer = NULL;
}

void	init_img_zero(t_img *image)
{
	image->img = NULL;
	image->addr = NULL;
	image->pixel_bits = 0;
	image->size_line = 0;
	image->endian = 0;
}
