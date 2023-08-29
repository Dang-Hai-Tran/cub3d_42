/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:39:55 by xuluu             #+#    #+#             */
/*   Updated: 2023/08/28 18:48:09 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_error(t_data *data, char *str, int id_line)
{
	data->error = 1;
	if (id_line == 0)
		printf("Error: %s !\n", str);
	else
		printf("Error: %s (line %d) !\n", str, id_line);
	return (1);
}

bool	ft_check_open_file(t_data *data, char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		printf("Error: '%s' isn't a file !\n", file);
		data->error = 1;
		close(fd);
		return (1);
	}
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: can't open '%s' !\n", file);
		data->error = 1;
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

bool	ft_check_file(t_data *data, char *file, char *type)
{
	int		i;

	if (ft_strchr(file, '.') == 0)
		return (1);
	i = ft_strlen(file) - 1;
	while (i > 0 && file[i] != '.')
		i--;
	if (ft_strncmp(&file[i], type, ft_strlen(type) + 1) != 0)
	{
		data->error = 1;
		printf("Error: '%s' not type (%s) !\n", file, type);
		return (1);
	}
	if (ft_check_open_file(data, file) == 1)
		return (1);
	return (0);
}
