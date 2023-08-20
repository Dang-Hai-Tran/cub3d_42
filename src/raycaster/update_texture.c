/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:38:51 by datran            #+#    #+#             */
/*   Updated: 2023/08/20 09:41:32 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture_pixels(t_display *display)
{
	int		i;

	if (display->textures_pixels)
		free_arr((void *)display->textures_pixels);
	display->textures_pixels = ft_calloc(display->win_height + 1, sizeof * display->textures_pixels);
	if (!display->textures_pixels)
		free_exit(display, err_msg("malloc display textures pixels", 1));
	i = 0;
	while (i < display->win_height)
	{
		display->textures_pixels[i] = ft_calloc(display->win_width + 1, sizeof * display->textures_pixels);
		if (!display->textures_pixels)
			free_exit(display, err_msg("malloc display textures pixels", 1));
		i++;
	}
}

static void	set_texinfo_index(t_display *display, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			display->texinfo->index = WEST;
		else
			display->texinfo->index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			display->texinfo->index = SOUTH;
		else
			display->texinfo->index = NORTH;
	}
}

void	update_texture_pixels(t_display *display, t_texinfo *texinfo, t_ray *ray, int x)
{
	int			y;
	int			color;

	set_texinfo_index(display, ray);
	texinfo->x = (int)(ray->wall_x * texinfo->size);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		texinfo->x = texinfo->size - texinfo->x - 1;
	texinfo->step = 1.0 * texinfo->size / ray->line_height;
	texinfo->pos = (ray->draw_start - display->win_height / 2
			+ ray->line_height / 2) * texinfo->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		texinfo->y = (int)texinfo->pos & (texinfo->size - 1);
		texinfo->pos += texinfo->step;
		color = display->textures[texinfo->index][texinfo->size * texinfo->y + texinfo->x];
		if (texinfo->index == NORTH || texinfo->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			display->textures_pixels[y][x] = color;
		y++;
	}
}
