/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:46:23 by colin             #+#    #+#             */
/*   Updated: 2023/08/15 11:30:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_display	display;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nWrong number of arguments\n", 1);
		return (EXIT_FAILURE);
	}
	else
		init_struct(&display, argv[1]);
	return (EXIT_SUCCESS);
}
