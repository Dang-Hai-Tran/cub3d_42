/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:10:13 by xuluu             #+#    #+#             */
/*   Updated: 2023/08/28 16:31:09 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_check_texture(t_texture *texture, char *line, int id_line)
{
	if (ft_strlen(line) < 4)
		return (1);
	if (ft_check_character_texture(line) == 1)
		return (1);
	if (ft_check_identifiant_texture(texture, line) == 1)
		return (1);
	if (ft_check_space_inside_texture(line) == 1)
		return (1);
	if (ft_check_path_to_texture(line) == 1)
		return (1);
	if (ft_check_double_texture(texture, id_line) == 1)
		return (1);
	return (0);
}

bool	ft_check_color(t_color *color, char *line, int id_line)
{
	if (ft_strlen(line) < 7)
		return (1);
	if (ft_check_character_color(line) == 1)
		return (1);
	if (ft_check_identifiant_color(color, line) == 1)
		return (1);
	if (ft_check_space_inside_color(line) == 1)
		return (1);
	if (ft_check_number_color(line) == 1)
		return (1);
	if (ft_check_double_color(color, id_line) == 1)
		return (1);
	return (0);
}

bool	ft_check_line(t_data *data, char *line, int id_line)
{
	if (data->m_map.find_map == true)
	{
		if (ft_check_map(&(data->m_map), line, id_line) == 0)
			return (0);
	}
	else if (data->m_map.find_map == false && ft_strlen(line) > 1
		&& data->m_texture.find_no == true && data->m_texture.find_so == true
		&& data->m_texture.find_we == true && data->m_texture.find_ea == true
		&& data->m_color.find_f == true && data->m_color.find_c == true)
	{
		if (ft_check_map(&(data->m_map), line, id_line) == 0)
			return (0);
	}
	else if (ft_check_texture(&(data->m_texture), line, id_line) == 0)
		return (0);
	else if (ft_check_color(&(data->m_color), line, id_line) == 0)
		return (0);
	else if (ft_strlen(line) == 1 && line[0] == '\n')
		return (0);
	return (1);
}

bool	ft_read_file(t_data *data, char *file)
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
		data->m_texture.id_texture = 0;
		data->m_color.id_color = 0;
		line = ft_gnl(fd);
		if (!line)
			break ;
		error = ft_check_line(data, line, id_line);
		free(line);
	}
	if (error == true)
		printf("Error < line %d >\n", id_line);
	return (error);
}
