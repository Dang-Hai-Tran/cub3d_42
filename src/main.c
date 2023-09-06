/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:46:23 by colin             #+#    #+#             */
/*   Updated: 2023/09/06 15:48:33 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void run_debug(t_display display)
{
	int		i;

	printf("Texture NO path = %s\n", display.texinfo->north);
	printf("Texture SO path = %s\n", display.texinfo->south);
	printf("Texture EA path = %s\n", display.texinfo->east);
	printf("Texture WE path = %s\n", display.texinfo->west);
	printf("Hex color of floor = %lu\n", display.texinfo->hex_floor);
	printf("Hex color of ceiling = %lu\n", display.texinfo->hex_ceiling);
	printf("Map width = %d\n", display.mapinfo->width);
	printf("Map height = %d\n", display.mapinfo->height);
	printf("Player position pos_x = %lf, pos_y = %lf\n", \
	display.player->pos_x, display.player->pos_y);
	i = -1;
	while (display.map[++i])
		printf("Map line[%d] = %s\n", i, display.map[i]);
}

int	main(int argc, char **argv)
{
	t_display	display;
	t_data		data;

	if (parsing_args(argc, argv, &data) == FAIL)
		return (FAIL);
	init_display(&display, &data);
	if (DEBUG)
		run_debug(display);
	init_mlx(&display);
	init_texbuffer(&display);
	render_images(&display);
	input_listen(&display);
	mlx_loop_hook(display.mlx, render_display, &display);
	mlx_loop(display.mlx);
	return (SUCCESS);
}
