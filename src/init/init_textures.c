/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:46:57 by datran            #+#    #+#             */
/*   Updated: 2023/08/22 23:15:18 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*xpm_to_img(t_display *display, char *path)
{
	t_img	image;
	int		*buf;
	int		x;
	int		y;

	init_texture(display, &image, path);
	buf = ft_calloc(1, sizeof * buf * display->texinfo->size * display->texinfo->size);
	if (!buf)
		free_exit(display, err_msg("calloc buf xpm to img", 1));
	y = 0;
	while (y < display->texinfo->size)
	{
		x = 0;
		while (x < display->texinfo->size)
		{
			buf[y * display->texinfo->size + x] = image.addr[y * display->texinfo->size + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(display->mlx, image.img);
	return (buf);
}

void	init_textures(t_display *display)
{
	display->textures = ft_calloc(5 , sizeof * display->textures);
	if (!display->textures)
		free_exit(display, err_msg("malloc", 1));
	display->textures[NORTH] = xpm_to_img(display, display->texinfo->north);
	display->textures[SOUTH] = xpm_to_img(display, display->texinfo->south);
	display->textures[EAST] = xpm_to_img(display, display->texinfo->east);
	display->textures[WEST] = xpm_to_img(display, display->texinfo->west);
}
