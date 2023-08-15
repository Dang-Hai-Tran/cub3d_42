/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 23:25:24 by datran            #+#    #+#             */
/*   Updated: 2023/08/14 15:02:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

# include "../libraries/libft/inc/libft.h"
# include "../libraries/gnl/inc/get_next_line.h"
# include "../libraries/minilibx/mlx.h"

# include "exit.h"
# include "init.h"
# include "move.h"
# include "raycasting.h"
# include "helpers.h"
# include "map.h"

# define BONUS 0

typedef struct s_img
{
	void		*img;
	int			*addr;
	int			pixel_bits;
	int			size_line;
	int			endian;
}	t_img;

typedef struct s_text
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			*floor;
	int			*ceiling;
	unsigned long		hex_floor;
	unsigned long		hex_ceiling;
	int			size;
	int			index;
	double		step;
	double		pos;
	int			x;
	int			y;
}	t_text;

typedef struct s_map
{
	int		fd;
	char	*filename;
	int		rows;
	int		cols;
	char	**pos;
	int		exists;
}	t_map;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	int			has_moved;
	int			move_x;
	int			move_y;
	int			rotate;
}	t_player;

typedef struct s_ray
{
	double		camera;

}	t_ray;

typedef struct s_display
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_map		*map;
	t_player	*player;
	t_ray		*ray;
	t_text		*text;
	char		**map_arr_str;
	int			**textures;
	int			**textures_pixels;
}	t_display;

enum e_direction
{
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3,
};

int map_parser(char *filename);

#endif
