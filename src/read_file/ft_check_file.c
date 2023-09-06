/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:30:43 by xuluu             #+#    #+#             */
/*   Updated: 2023/09/06 15:06:19 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_is_a_file(char *file, int id_line, char *direc)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		if (id_line == 0)
			printf("Error: '%s' isn't a file !\n", file);
		else
			printf("Error: [%d] '%s' isn't a file of (%s) !\n",
				id_line, file, direc);
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

bool	ft_check_open_file(char *file, int id_line, char *direc)
{
	int	fd;

	if (ft_is_a_file(file, id_line, direc) == 1)
		return (1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		if (id_line == 0)
			printf("Error: can't open '%s' !\n", file);
		else
			printf("Error: [%d] can't open '%s' of (%s) !\n",
				id_line, file, direc);
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

bool	ft_is_empty_file(char *file, int id_line, char *direc)
{
	int		fd;
	int		nb_line;
	char	*line;

	fd = open(file, O_RDONLY);
	nb_line = 0;
	while (nb_line >= 0)
	{
		line = ft_gnl_bonus(fd);
		if (!line)
			break ;
		nb_line++;
		free(line);
	}
	if (nb_line == 0)
	{
		if (id_line == 0)
			printf("Error: '%s' is empty file !\n", file);
		else
			printf("Error: [%d] '%s' is empty file (%s) !\n",
				id_line, file, direc);
		return (1);
	}
	return (0);
}

bool	ft_check_file2(char *file, char *type, int id_line, char *direc)
{
	int		i;

	i = ft_strlen(file) - 1;
	while (i > 0 && file[i] != '.')
		i--;
	if (ft_strncmp(&file[i], type, ft_strlen(type) + 1) != 0)
	{
		if (id_line == 0)
			printf("Error: '%s' not a file type (%s) !\n", file, type);
		else
			printf("Error: [%d] '%s' not a file type (%s) of (%s) !\n",
				id_line, file, type, direc);
		return (1);
	}
	if (ft_check_open_file(file, id_line, direc) == 1)
		return (1);
	if (ft_is_empty_file(file, id_line, direc) == 1)
		return (1);
	return (0);
}

bool	ft_check_file(char *file, char *type, int id_line, char *direc)
{
	if (ft_strchr(file, '.') == 0)
	{
		if (id_line == 0)
			printf("Error: '%s' not a file type (%s) !\n", file, type);
		else
			printf("Error: [%d] '%s' not a file type (%s) of (%s) !\n",
				id_line, file, type, direc);
		return (1);
	}
	return (ft_check_file2(file, type, id_line, direc));
}
