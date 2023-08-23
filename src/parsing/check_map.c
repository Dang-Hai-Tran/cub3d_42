/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:59:32 by datran            #+#    #+#             */
/*   Updated: 2023/08/23 11:08:47 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	get_player_direction(char p_char, t_player *player)
{
	if (ft_strchr("NSEW", p_char) && player->dir != UNDEFINED)
		return (false);
	if (ft_strchr("NSEW", p_char) && player->dir == UNDEFINED)
	{
		if (p_char == 'N')
			player->dir = NORTH;
		if (p_char == 'S')
			player->dir = SOUTH;
		if (p_char == 'E')
			player->dir = EAST;
		if (p_char == 'W')
			player->dir = WEST;
	}
	return (true);
}

static int	check_map_chars(char **map, t_player *player, int height, int width)
{
	int		i;
	int		j;
	
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (!ft_strchr("10NSEW", map[i][j]) && !ft_isspace(map[i][j]))
				return (err_msg("map character invalid", FAIL));
			if (!get_player_direction(map[i][j], player))
				return (err_msg("more than one character player", FAIL));
			j++;
		}
		i++;
	}
	return (SUCCESS);
}


static int	check_position_player(char **map, t_player *player, int height, int width)
{
	int		i;
	int		j;

	if (player->dir == UNDEFINED)
		return (err_msg("not found player position", FAIL));
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				player->pos_x = (double)j + 0.5;
				player->pos_y = (double)i + 0.5;
				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (check_player_has_wall_around(map, player, height, width) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	check_map(char **map, t_player *player, t_mapinfo *mapinfo)
{
	if (check_map_chars(map, player, mapinfo->height, mapinfo->width) == FAIL)
		return (FAIL);
	if (check_position_player(map, player, mapinfo->height, mapinfo->width) == FAIL)
		return (FAIL);
	if (check_map_sides(map, mapinfo->height, mapinfo->width) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
