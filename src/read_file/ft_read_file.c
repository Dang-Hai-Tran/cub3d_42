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

bool	ft_check_texture(t_data *data, char *line, int id_line)
{
	if (ft_strlen(line) < 4)
		return (1);
	if (ft_check_character_texture(line) == 1)
		return (1);
	if (ft_check_identifiant_texture(&(data->m_texture), line) == 1)
		return (1);
	if (ft_check_space_inside_texture(line) == 1)
		return (ft_error(data, "Invalid space", id_line));
	if (ft_check_path_to_texture(data, line) == 1)
		return (1);
	if (ft_check_double_texture(&(data->m_texture), id_line) == 1)
		return (ft_error(data, "Double texture in file", id_line));
	return (0);
}

bool	ft_check_color(t_data *data, char *line, int id_line)
{
	if (ft_strlen(line) < 7)
		return (1);
	if (ft_check_character_color(line) == 1)
		return (1);
	if (ft_check_identifiant_color(&(data->m_color), line) == 1)
		return (1);
	if (ft_check_space_inside_color(line) == 1)
		return (ft_error(data, "Invalid space", id_line));
	if (ft_check_number_color(line) == 1)
		return (ft_error(data, "Invalid number", id_line));
	if (ft_check_double_color(&(data->m_color), id_line) == 1)
		return (ft_error(data, "Double color in file", id_line));
	return (0);
}

bool	ft_check_line(t_data *data, char *line, int id_line)
{
	if (data->m_map.find_map == true)
	{
		if (ft_check_map(data, line, id_line) == 0)
			return (0);
	}
	else if (data->m_map.find_map == false && ft_strlen(line) > 1
		&& data->m_texture.find_no == true && data->m_texture.find_so == true
		&& data->m_texture.find_we == true && data->m_texture.find_ea == true
		&& data->m_color.find_f == true && data->m_color.find_c == true)
	{
		if (ft_check_map(data, line, id_line) == 0)
			return (0);
	}
	else if (ft_check_texture(data, line, id_line) == 0)
		return (0);
	else if (ft_check_color(data, line, id_line) == 0)
		return (0);
	else if (ft_strlen(line) == 1 && line[0] == '\n')
		return (0);
	if (data->error == 0)
		printf("Error: Invalid line %d !\n", id_line);
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
		data->error = 0;
		error = ft_check_line(data, line, id_line);
		free(line);
	}
	return (error);
}
