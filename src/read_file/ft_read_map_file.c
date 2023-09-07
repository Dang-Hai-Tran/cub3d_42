/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:29:17 by xuluu             #+#    #+#             */
/*   Updated: 2023/09/06 18:33:52 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_check_line_space(char *str)
{
	int	i;
	int	nbr_space;

	nbr_space = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == ' ')
			nbr_space++;
		i++;
	}
	if (!str[i] && nbr_space == (int)ft_strlen(str))
		return (1);
	if (nbr_space > 0 && nbr_space == (int)ft_strlen(str) - 1)
		return (1);
	return (0);
}

bool	ft_determine_line2(t_data *data)
{
	int	i;

	i = ft_ignore_space_start(data->m_line.line);
	if (ft_check_texture(data, &(data->m_line.line[i])) == 0)
		return (0);
	else if (data->error == 0
		&& ft_check_color(data, &(data->m_line.line[i])) == 0)
		return (0);
	else if (data->error == 0
		&& ft_check_map(data, data->m_line.line) == 0)
		return (0);
	return (1);
}

bool	ft_determine_line(t_data *data)
{
	int	i;

	i = ft_ignore_space_start(data->m_line.line);
	if (ft_check_line_space(data->m_line.line) == 1)
	{
		if (ft_check_empty_line(data) == 1)
			return (1);
		if (data->m_map.find_map == false)
		{
			data->m_map.line_start = data->m_line.id_line;
			data->m_map.find_map = true;
		}
		ft_get_size_map(data, data->m_line.line);
		return (0);
	}
	else if (data->m_line.line[i] == '\n')
	{
		data->m_line.id_line_new_line = 0;
		if (data->m_map.find_map == true)
			data->m_line.id_line_new_line = data->m_line.id_line;
		return (0);
	}
	return (ft_determine_line2(data));
}

bool	ft_read_map_file(t_data *data, char *file)
{
	int		fd;
	bool	error;

	fd = open(file, O_RDONLY);
	data->m_line.id_line = 0;
	error = false;
	while (42)
	{
		data->m_line.line = ft_gnl_bonus(fd);
		if (!data->m_line.line)
			break ;
		data->m_line.id_line++;
		data->error = 0;
		if (error == 0)
			error = ft_determine_line(data);
		free(data->m_line.line);
	}
	if (error == 0)
		error = ft_check_file_status(data, file);
	close(fd);
	return (error);
}
