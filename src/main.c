/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:46:23 by colin             #+#    #+#             */
/*   Updated: 2023/08/28 18:50:27 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_display	display;
	t_data		data;

	if (parsing_args(argc, argv, &data) == FAIL)
		return (err_msg("parsing error", 1));
	init_display(&display, &data);
	init_mlx(&display);
	init_texbuffer(&display);
	render_images(&display);
	input_listen(&display);
	mlx_loop_hook(display.mlx, render_display, &display);
	mlx_loop(display.mlx);
	return (SUCCESS);
}
