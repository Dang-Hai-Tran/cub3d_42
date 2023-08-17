/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:54:13 by codespace         #+#    #+#             */
/*   Updated: 2023/08/17 00:27:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "cub3d.h"

void		fill_map(t_display *display, char *filename);
int			is_map_walled(t_map	*map, t_display *display);
void		create_map(t_display *display, int fd);
int			parse_texture_path(char *line, char **path);
int			parse_rgb_color(char *line, unsigned long *rgb);
t_display	*parse_map_file(t_display *display, char *filename);

#endif