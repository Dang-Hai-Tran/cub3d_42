/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:40:46 by datran            #+#    #+#             */
/*   Updated: 2023/08/28 14:27:29 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_exit(t_display *display, int exit_code)
{
	if (!display)
		exit(exit_code);
	if (display->win && display->mlx)
		mlx_destroy_window(display->mlx, display->win);
	if (display->mlx)
	{
		mlx_destroy_display(display->mlx);
		mlx_loop_end(display->mlx);
		if (display->mlx)
			free(display->mlx);
	}
	free_display(display);
	exit(exit_code);
}

int	quit_cub3d(t_display *display)
{
	free_exit(display, 0);
	ft_putendl_fd("Exit cub3d by (x)", STDOUT_FILENO);
	return (0);
}
