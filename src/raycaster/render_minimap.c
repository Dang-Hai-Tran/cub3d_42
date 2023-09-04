/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:00:01 by datran            #+#    #+#             */
/*   Updated: 2023/09/04 15:16:14 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_minimap(t_display *display)
{
	t_minimap		minimap;

	init_minimap(&minimap, display);
	minimap.map = create_minimap_map(&minimap, display);
	render_minimap_image(&minimap, display);
	free_arr((void **)minimap.map);
}
