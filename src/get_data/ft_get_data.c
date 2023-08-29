/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:49:52 by xuluu             #+#    #+#             */
/*   Updated: 2023/08/29 18:13:31 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_get_str(char *str)
{
	int		i;
	char	*new_str;

	new_str = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!new_str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}

void	ft_read_file3(t_data *data, char *file)
{
	int		fd;
	int		id_line;
	char	*line;

	fd = open(file, O_RDONLY);
	id_line = 0;
	while (true)
	{
		id_line++;
		line = ft_gnl(fd);
		if (!line)
			break ;
		if (id_line == data->m_texture.line_no
			|| id_line == data->m_texture.line_so
			|| id_line == data->m_texture.line_we
			|| id_line == data->m_texture.line_ea)
			ft_get_texture(data, line, id_line);
		else if (id_line == data->m_color.line_f
			|| id_line == data->m_color.line_c)
			ft_get_color(data, line, id_line);
		free(line);
	}
	close(fd);
}

void	ft_get_data(t_data *data, char *file)
{
	ft_read_file3(data, file);
	ft_get_map(data, file);
	return ;
}
