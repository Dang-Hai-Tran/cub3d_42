/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:46:23 by colin             #+#    #+#             */
/*   Updated: 2023/08/20 11:15:04 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	main(int argc, char **argv)
{
	t_display	display;

	if (argc != 2)
		return (err_msg("Wrong number of arguments", 1));
	init_struct(&display, argv[1]);
	parse_map_file(&display, argv[1]);
	return (0);
}
