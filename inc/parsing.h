/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:48:24 by xuluu             #+#    #+#             */
/*   Updated: 2023/09/06 15:05:03 by datran           ###   ########.fr       */
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
	int		nb_number;
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

typedef struct s_line
{
	int		id_line;
	int		id_line_new_line;
	char	*line;
}	t_line;

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

	t_line		m_line;
	t_texture	m_texture;
	t_color		m_color;
	t_map		m_map;
	t_pplayer	m_player;
}	t_data;

/********************************************************/
void	ft_initialisation_data(t_data *data);
bool	ft_check_file(char *file, char *type, int id_line, char *direc);
bool	ft_read_map_file(t_data *data, char *file);

/*
utiles
*/
int		ft_ignore_space_start(char *str);
int		ft_ignore_space_end(char *str);
bool	ft_check_file_status(t_data *data, char *file);
bool	ft_check_position_map(t_data *data);
bool	ft_check_start_space(t_data *data);
bool	ft_check_end_space(t_data *data, char *str);
bool	ft_check_find_elements(t_data *data);

/*
texture
*/
char	*ft_error_texture(t_texture *texture);
bool	ft_check_texture(t_data *data, char *str);
bool	ft_check_path(t_data *data, char *str);
char	*ft_copy_str(char *str, int start, int end);

/*
color
*/
char	*ft_error_color(t_color *color);
bool	ft_check_color(t_data *data, char *str);
bool	ft_check_number_color(t_data *data, char *str);
bool	ft_check_double_color(t_color *color, int id_line);
char	*ft_get_str_number(char *str);

/*
map
*/
bool	ft_check_map(t_data *data, char *str);
bool	ft_check_map_open(t_data *data, char *file);
void	ft_set_value_to_map(t_map *map, char *file, char **tab);
void	ft_get_size_map(t_data *data, char *str);
bool	ft_check_empty_line(t_data *data);

/*
player
*/
bool	ft_find_player(t_data *data);
bool	ft_check_nomber_player(t_data *data, char *str);

/*
get data
*/
void	ft_get_data(t_data *data, char *file);
void	ft_get_texture(t_data *data, char *str, int id_line);
void	ft_get_color(t_data *data, char *str, int id_line);
void	ft_get_map(t_data *data, char *file);
char	*ft_get_str(char *str);
void	ft_print_information(t_data *data);

/*
parsing
*/
bool	parsing_args(int argc, char **argv, t_data *data);

#endif
