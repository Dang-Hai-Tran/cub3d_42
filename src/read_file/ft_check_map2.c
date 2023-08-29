/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:10:48 by xuluu             #+#    #+#             */
/*   Updated: 2023/08/28 16:31:09 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_check_size_map(t_data *data)
{
	if (data->m_map.width < 3 || data->m_map.height < 3)
		return (ft_error(data, "Invalid size map (min map 3x3)", 0));
	return (0);
}

bool	ft_check_outside_map(t_map *map, char *line, int id_line)
{
	if (ft_check_line_space(line) == 0)
	{
		if (id_line == map->line_start
			|| id_line == map->line_end)
		{
			if (ft_check_line_start_and_end(line) == 0)
				return (0);
		}
		else if (ft_check_line_map_open(line) == 0)
			return (0);
		return (1);
	}
	return (0);
}

bool	ft_check_line_map(t_data *data, char *line, int id_line)
{
	if (ft_check_outside_map(&(data->m_map), line, id_line) == 0)
	{
		if (ft_check_nombre_player(&(data->m_player), line) == 1)
			return (ft_error(data,
					"just 1 Player in map", id_line));
		if (id_line == data->m_map.line_end
			&& data->m_player.find_player == false)
			return (1);
		return (0);
	}
	return (ft_error(data, "Invalid map", id_line));
}

bool	ft_read_map(t_data *data, char *file)
{
	int		fd;
	int		id_line;
	bool	error;
	char	*line;

	fd = open(file, O_RDONLY);
	id_line = 0;
	error = false;
	while (error == false)
	{
		id_line++;
		line = ft_gnl(fd);
		if (!line)
			break ;
		if (id_line >= data->m_map.line_start
			&& id_line <= data->m_map.line_end)
			error = ft_check_line_map(data, line, id_line);
		else if (id_line > data->m_map.line_end)
			error = 1;
		free(line);
	}
	return (error);
}

bool	ft_check_map2(t_data *data, char *file)
{
	if (ft_check_size_map(data) == 0)
	{
		if (ft_read_map(data, file) == 0)
			return (0);
	}
	return (1);
}
