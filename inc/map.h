/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:54:13 by codespace         #+#    #+#             */
/*   Updated: 2023/08/15 11:28:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include "cub3d.h"

void	load_map(t_display *display, char *filename);
int		is_map_walled(t_map	*map, t_display *display);
void	create_map(t_display *display, int fd);

#endif