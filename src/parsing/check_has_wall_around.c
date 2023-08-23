/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_has_wall_around.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:21:55 by datran            #+#    #+#             */
/*   Updated: 2023/08/23 10:45:49 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_has_wall_left(char **map, t_player *player)
{
	int		i;
	int		j;
	int		x;
	bool	ret;

	i = (int)player->pos_y;
	j = (int)player->pos_x;
	x = 0;
	while (x < j)
	{
		if (map[i][x] == '1')
			break;
		x++;
	}
	if (x < j)
		ret = true;
	else
		ret = false;
	return (ret);
}

static bool	check_has_wall_right(char **map, t_player *player, int width)
{
	int		i;
	int		j;
	int		x;
	bool	ret;

	i = (int)player->pos_y;
	j = (int)player->pos_x;
	x = j + 1;
	while (x < width)
	{
		if (map[i][x] == '1')
			break;
		x++;
	}
	if (x < width)
		ret = true;
	else
		ret = false;
	return (ret);
}

static bool	check_has_wall_down(char **map, t_player *player, int height)
{
	int		i;
	int		j;
	int		y;
	bool	ret;

	i = (int)player->pos_y;
	j = (int)player->pos_x;
	y = i + 1;
	while (y < height)
	{
		if (map[y][j] == '1')
			break;
		y++;
	}
	if (y < height)
		ret = true;
	else
		ret = false;
	return (ret);
}

static bool	check_has_wall_up(char **map, t_player *player)
{
	int		i;
	int		j;
	int		y;
	bool	ret;

	i = (int)player->pos_y;
	j = (int)player->pos_x;
	y = 0;
	while (y < i)
	{
		if (map[y][j] == '1')
			break;
		y++;
	}
	if (y < i)
		ret = true;
	else
		ret = false;
	return (ret);
}

int	check_player_has_wall_around(char **map, t_player *player, int height, int width)
{
	if (!check_has_wall_left(map, player) || !check_has_wall_right(map, player, width) || !check_has_wall_up(map, player) || !check_has_wall_down(map, player, height))
		return (err_msg("player don't have enough wall around", FAIL));
	return (SUCCESS);
}
