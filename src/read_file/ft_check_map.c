/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:15:34 by xuluu             #+#    #+#             */
/*   Updated: 2023/08/28 16:31:09 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_check_character_map(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '0'
			&& str[i] != '1'
			&& str[i] != 'N'
			&& str[i] != 'S'
			&& str[i] != 'E'
			&& str[i] != 'W'
			&& str[i] != ' ')
			return (1);
		i++;
	}
	if (i == 0)
		return (1);
	if (ft_check_line_space(str) == 0
		&& str[i - 1] != '1')
		return (1);
	return (0);
}

bool	ft_check_line_without_1(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == '1')
			return (0);
		i++;
	}
	return (1);
}

bool	ft_check_line_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	ft_get_size_map(t_map *map, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	if (len > map->width)
		map->width = len;
	map->height = map->line_end - map->line_start + 1;
}

bool	ft_check_map(t_map *map, char *line, int id_line)
{
	if (ft_check_character_map(line) == 1)
		return (1);
	if (ft_check_line_space(line) == 0)
	{
		if (ft_check_line_without_1(line) == 1)
			return (1);
		if (map->find_map == false)
		{
			map->find_map = true;
			map->line_start = id_line;
		}
		map->line_end = id_line;
		ft_get_size_map(map, line);
	}
	if (map->find_map == false)
		return (1);
	return (0);
}
