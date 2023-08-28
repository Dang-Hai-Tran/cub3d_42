/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:39:55 by xuluu             #+#    #+#             */
/*   Updated: 2023/08/28 17:07:16 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_check_open_file(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
		return (err_msg("map file is directory", FAIL));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (err_msg("can't open map file", FAIL));
	return (SUCCESS);
}

bool	ft_check_file(char *file, char *type)
{
	int		i;

	if (ft_strchr(file, '.') == 0)
		return (1);
	i = ft_strlen(file) - 1;
	while (i > 0 && file[i] != '.')
		i--;
	if (ft_strncmp(&file[i], type, ft_strlen(type) + 1) != 0)
	{
		printf("Error < %s not type (%s) > !\n", file, type);
		return (1);
	}
	printf("end = [%s]\n", &file[i]);
	if (ft_check_open_file(file) == 1)
		return (1);
	return (0);
}
