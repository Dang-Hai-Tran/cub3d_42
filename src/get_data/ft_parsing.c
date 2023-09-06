/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:30:43 by xuluu             #+#    #+#             */
/*   Updated: 2023/09/06 15:06:19 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parsing_args(int argc, char **argv, t_data *data)
{
	if (argc != 2)
	{
		printf("Error: number arguments is invalid !\n");
		return (1);
	}
	if (ft_check_file(argv[1], ".cub", 0, NULL) == 1)
		return (1);
	ft_initialisation_data(data);
	if (ft_read_map_file(data, argv[1]) == 1)
		return (1);
	ft_get_data(data, argv[1]);
	return (0);
}
