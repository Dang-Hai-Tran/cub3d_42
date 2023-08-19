/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:46:57 by datran            #+#    #+#             */
/*   Updated: 2023/08/15 11:14:25 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texinfo(t_texinfo *texinfo)
{
	texinfo->north = NULL;
	texinfo->south = NULL;
	texinfo->east = NULL;
	texinfo->west = NULL;
	texinfo->floor = 0;
	texinfo->ceiling = 0;
	texinfo->hex_ceiling = 0;
	texinfo->hex_floor = 0;
	texinfo->size = TEX_SIZE;
	texinfo->step = 0;
	texinfo->pos = 0.0;
	texinfo->x = 0;
	texinfo->y = 0;
}
