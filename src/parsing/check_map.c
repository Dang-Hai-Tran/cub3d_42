/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:59:32 by datran            #+#    #+#             */
/*   Updated: 2023/08/22 22:43:45 by datran           ###   ########.fr       */
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

static int	check_map_chars(char **map, t_player *player)
{
	int		i;
	int		j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
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

static int	check_position_space_around(char **map, t_player *player)
{
	int		i;
	int		j;

	i = (int)player->pos_y;
	j = (int)player->pos_x;
	if (ft_isspace(map[i - 1][j]) || ft_isspace(map[i + 1][j]) || ft_isspace(map[i][j - 1]) || ft_isspace(map[i][j + 1]))
		return (err_msg("have space around player", FAIL));
	return (SUCCESS);
}

static int	check_position_player(char **map, t_player *player)
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
	if (check_position_space_around(map, player) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	check_map(char **map, t_player *player, t_mapinfo *mapinfo)
{
	if (check_map_chars(map, player) == FAIL)
		return (FAIL);
	if (check_position_player(map, player) == FAIL)
		return (FAIL);
	if (check_map_sides(mapinfo, map) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
