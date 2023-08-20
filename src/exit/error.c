/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:52:12 by datran            #+#    #+#             */
/*   Updated: 2023/08/12 15:56:09 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	err_msg(char *str, int code)
{
	ft_putstr_fd("Error", STDERR_FILENO);
	if (str)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
	}
	ft_putstr_fd("\n", STDERR_FILENO);
	return (code);
}

void	ft_error_fd(char *str, int fd, t_display *display)
{
	ft_putstr_fd(str, fd);
	free_exit(display, 1);
	exit(1);
}