/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:24:47 by codespace         #+#    #+#             */
/*   Updated: 2023/08/17 00:24:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include "cub3d.h"

char	*ft_strstr(const char *s1, const char *s2);
long	ft_strtol(const char *nptr, char **endptr, int base);
void	check_line(char *line, t_display *display);
void	nb_rowcols(t_display *display, int fd);
void	check_outer_wall(t_map *map, int i, t_display *display);
char	*skip_whitespace(char *line);
int		is_adjacent_valid(t_map *map, int i, int j);
void	fill_adjacents(char *directions, t_map *map, int i, int j, int row_length);
int		is_adjacent_char_valid(char current, char neighbor);
int		is_map_rectangle(t_display *display, int len2);
int		is_map_line(char* line);

void	print_map(t_display *display);

#endif