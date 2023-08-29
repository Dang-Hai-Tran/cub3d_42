/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:53:19 by xuluu             #+#    #+#             */
/*   Updated: 2023/08/28 18:47:23 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parsing_args(int argc, char **argv, t_data *data)
{
	if (argc != 2)
		return (ft_error(data, "Number arguments is invalid", 0));
	if (ft_check_file(data, argv[1], ".cub") == 1)
		return (1);
	if (ft_check_nombre_line_in_file(argv[1]) == 1)
		return (1);
	ft_initialisation_data(data);
	if (ft_read_file(data, argv[1]) == 1)
		return (1);
	if (ft_check_map2(data, argv[1]) == 1)
		return (1);
	if (ft_check_inside_map(data, argv[1]) == 1)
		return (1);
	ft_get_data(data, argv[1]);
	return (0);
}