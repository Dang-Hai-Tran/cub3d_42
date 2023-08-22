/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:30:34 by datran            #+#    #+#             */
/*   Updated: 2023/08/22 23:18:32 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parsing_args(int argc, char **argv, t_display *display)
{
	if (check_args(argc, argv, display->mapinfo) == FAIL)
		return (FAIL);
	if (get_mapinfo(display->mapinfo->fd, display->mapinfo) == FAIL)
		return (FAIL);
	if (get_texinfo(display->mapinfo->lines, display->texinfo) == FAIL)
		return (FAIL);
	if (get_map_game(display->mapinfo->lines, display->mapinfo->nb_lines, display->mapinfo, display) == FAIL)
		return (FAIL);
	init_player_dir(display->player);
	return (SUCCESS);
}
