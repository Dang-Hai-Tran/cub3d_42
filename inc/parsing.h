/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:48:24 by xuluu             #+#    #+#             */
/*   Updated: 2023/08/29 16:19:03 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

typedef struct s_texture
{
	int		id_texture;
	bool	find_no;
	bool	find_so;
	bool	find_we;
	bool	find_ea;
	int		line_no;
	int		line_so;
	int		line_we;
	int		line_ea;
}	t_texture;

typedef struct s_color
{
	int		id_color;
	bool	find_f;
	bool	find_c;
	int		line_f;
	int		line_c;
}	t_color;

typedef struct s_map
{
	bool	find_map;
	int		width;
	int		height;
	int		line_start;
	int		line_end;
}	t_map;

typedef struct s_pplayer
{
	bool	find_player;
	char	p_char;
	int		p_col;
	int		p_row;
}	t_pplayer;

typedef struct s_data
{
	char		**map;
	int			*rgb_floor;
	int			*rgb_ceiling;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	bool		error;

	t_texture	m_texture;
	t_color		m_color;
	t_map		m_map;
	t_pplayer	m_player;
}	t_data;

void	ft_print_information(t_data *data);

/*
ft_check_file
*/
bool	ft_error(t_data *data, char *str, int id_line);
bool	ft_check_file(t_data *data, char *file, char *type);
bool	ft_check_nombre_line_in_file(char *file, t_data *data);
bool	ft_read_file(t_data *data, char *file);

/*
ft_initialisation.c
*/
void	ft_initialisation_data(t_data *data);

/*
ft_check_texture.c
*/
bool	ft_check_character_texture(char *str);
bool	ft_check_identifiant_texture(t_texture *texture, char *str);
bool	ft_check_space_inside_texture(char *str);
bool	ft_check_path_to_texture(t_data *data, char *str);
bool	ft_check_double_texture(t_texture *texture, int id_line);

/*
ft_check_color.c
*/
bool	ft_check_character_color(char *str);
bool	ft_check_identifiant_color(t_color *color, char *str);
bool	ft_check_space_inside_color(char *str);
bool	ft_check_double_color(t_color *color, int id_line);

/*
ft_check_number_color.c
*/
bool	ft_check_number_color(char *str);
bool	ft_read_str_number(char *str);
char	*ft_get_char_number_color(char *str);

/*
ft_check_map.c
*/
bool	ft_check_map(t_data *data, char *line, int id_line);
bool	ft_check_map2(t_data *data, char *file);
bool	ft_check_line_start_and_end(char *str);
bool	ft_check_line_map_open(char *str);
bool	ft_check_line_space(char *str);
bool	ft_check_nombre_player(t_pplayer *player, char *str);
bool	ft_check_inside_map(t_data *data, char *file);
void	ft_set_value_to_map(t_map *map, char *file, char **tab);

/*
ft_get_data.c
*/
void	ft_get_data(t_data *data, char *file);
char	*ft_get_str(char *str);
void	ft_get_texture(t_data *data, char *str, int id_line);
void	ft_get_color(t_data *data, char *str, int id_line);
void	ft_get_map(t_data *data, char *file);

/*
parsing_args.c
*/
int	parsing_args(int argc, char **argv, t_data *data);

#endif
