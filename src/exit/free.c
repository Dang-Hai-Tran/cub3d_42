/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:44:52 by datran            #+#    #+#             */
/*   Updated: 2023/08/23 09:18:57 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_arr(void **arr)
{
	size_t		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	if (arr)
	{
		free(arr);
		arr = NULL;
	}
}

static void free_mapinfo(t_mapinfo *mapinfo)
{
	if (mapinfo->fd > 0)
		close(mapinfo->fd);
	if (mapinfo->path)
		free(mapinfo->path);
	if (mapinfo->lines)
		free_arr((void **)mapinfo->lines);
	if (mapinfo)
		free(mapinfo);
}

static void free_texinfo(t_texinfo *texinfo)
{
	if (texinfo->north)
		free(texinfo->north);
	if (texinfo->south)
		free(texinfo->south);
	if (texinfo->east)
		free(texinfo->east);
	if (texinfo->west)
		free(texinfo->west);
	if (texinfo->rgb_floor)
		free(texinfo->rgb_floor);
	if (texinfo->rgb_ceiling)
		free(texinfo->rgb_ceiling);
	if (texinfo)
		free(texinfo);
}

static void free_player(t_player *player)
{
	if (player)
		free(player);
}

static void free_ray(t_ray *ray)
{
	if (ray)
		free(ray);
}

void	free_display(t_display *display)
{
	if (display->texbuffer)
		free_arr((void **)display->texbuffer);
	if (display->texpixels)
		free_arr((void **)display->texpixels);
	if (display->map)
		free_arr((void **)display->map);
	free_texinfo(display->texinfo);
	free_mapinfo(display->mapinfo);
	free_player(display->player);
	free_ray(display->ray);
}
