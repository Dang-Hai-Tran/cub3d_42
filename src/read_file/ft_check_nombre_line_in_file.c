/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_nombre_line_in_file.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:10:13 by xuluu             #+#    #+#             */
/*   Updated: 2023/08/28 16:31:09 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_check_nombre_line_in_file(char *file)
{
	int		fd;
	int		nbr_line;
	char	*line;

	fd = open(file, O_RDONLY);
	nbr_line = 0;
	while (42)
	{
		line = ft_gnl(fd);
		if (!line)
			break ;
		free(line);
		nbr_line++;
	}
	if (nbr_line < 9)
		return (ft_error("file has 9 lines minimum", 0));
	return (0);
}
