/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:46:23 by colin             #+#    #+#             */
/*   Updated: 2023/08/23 09:19:39 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_display	display;

	init_display(&display);
	if (parsing_args(argc, argv, &display) == FAIL)
		free_exit(&display, FAIL);
	init_mlx(&display);
	init_texbuffer(&display);
	render_images(&display);
	input_listen(&display);
	mlx_loop_hook(display.mlx, render_display, &display);
	mlx_loop(display.mlx);
	return (SUCCESS);
}
