/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:23:46 by codespace         #+#    #+#             */
/*   Updated: 2023/08/15 11:25:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_outer_wall(t_map *map, int i, t_display *display)
{
	int	j;
	int	row_length;

	row_length = ft_strlen(map->pos[i]);
	j = 0;
	while (j < row_length)
	{
		if (map->pos[i][j] != '1' && map->pos[i][j] != ' ')
			ft_error_fd("Rows are not walled correctly!\n", 1, display);
		j++;
	}
}
