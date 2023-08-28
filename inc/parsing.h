/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:29:46 by datran            #+#    #+#             */
/*   Updated: 2023/08/28 13:59:20 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

typedef enum e_dir			t_dir;
typedef enum e_code			t_code;
typedef struct s_img		t_img;
typedef struct s_texinfo	t_texinfo;
typedef struct s_mapinfo	t_mapinfo;
typedef struct s_ray		t_ray;
typedef struct s_player		t_player;
typedef struct s_display	t_display;

char			*ft_strstr(const char *s1, const char *s2);
char			*remove_white_space(char *str);
bool			check_rgb_value(int *rgb_arr);
unsigned long	rgb_to_hex(int *rgb_arr);
int				get_texinfo(char **lines, t_texinfo *texinfo);
bool			str_contain_only_digits(char *str);
int				check_map(char **map, t_player *player, t_mapinfo *mapinfo);
int				get_map_game(char **lines, int nb_lines, t_mapinfo *mapinfo, \
t_display *display);
int				parsing_args(int argc, char **argv, t_display *display);
int				check_args(int argc, char **argv, t_mapinfo *mapinfo);
bool			arg_is_valid_ext(char *path, char *ext);
int				get_mapinfo(int fd, t_mapinfo *mapinfo);
void			remove_backslash_end(char *str);
int				check_map_sides(char **map, int height, int width);
int				check_player_has_wall_around(char **map, t_player *player, \
int height, int width);

#endif
