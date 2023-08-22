/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:57:22 by datran            #+#    #+#             */
/*   Updated: 2023/08/22 13:31:22 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	valid_number_args(int argc)
{
	if (argc != 2)
	{
		err_msg("Wrong number of arguments", 1);
		return (false);
	}
	return (true);
}

static bool	arg_is_dir(char **argv)
{
	int		fd;

	fd = open(argv[1], O_DIRECTORY);
	close(fd);
	if (fd >= 0)
	{
		err_msg("Map file is directory", 1);
		return (true);
	}
	return (false);
}

static bool arg_is_cub_file(char **argv)
{
	char	*tmp;

	tmp = ft_strstr(argv[1], ".cub");
	if (tmp && ft_strlen(tmp) == 4)
		return (true);
	err_msg("Map file isn't cub file", 1);
	return (false);
}


int	check_args(int argc, char **argv, t_mapinfo *mapinfo)
{
	int		fd;

	if (!valid_number_args(argc) || arg_is_dir(argv) || !arg_is_cub_file(argv))
		return (FAIL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		err_msg("Can't open map file", 1);
		return (FAIL);
	}
	mapinfo->path = ft_strdup(argv[1]);
	mapinfo->fd = fd;
	return (SUCCESS);
}
