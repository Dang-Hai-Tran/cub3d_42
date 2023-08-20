/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 23:25:24 by datran            #+#    #+#             */
/*   Updated: 2023/08/20 12:22:29 by datran           ###   ########.fr       */
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
# include "helpers.h"
# include "map.h"
# include "raycaster.h"

# define BONUS 0

typedef struct s_img t_img;
typedef struct s_texinfo t_texinfo;
typedef struct s_mapinfo t_mapinfo;
typedef struct s_ray t_ray;
typedef struct s_player t_player;
typedef struct s_display t_display;
typedef enum e_dir t_dir;

typedef struct s_img
{
	void		*img;
	int			*addr;
	int			pixel_bits;
	int			size_line;
	int			endian;
}	t_img;

typedef struct s_texinfo
{
	char				*north;
	char				*south;
	char				*west;
	char				*east;
	int					*floor;
	int					*ceiling;
	unsigned long		hex_floor;
	unsigned long		hex_ceiling;
	unsigned long		*ceiling_rgb;
	unsigned long		*floor_rgb;
	int					size;
	int					index;
	double				step;
	double				pos;
	int					x;
	int					y;
}	t_texinfo;

typedef struct s_mapinfo
{
	int		fd;
	int		line_count;
	char	*path;
	int		height;
	int		width;
	int		rows;
	int		cols;
}	t_mapinfo;

typedef struct s_player
{
	t_dir		dir;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			has_moved;
	int			move_x;
	int			move_y;
	int			rotate;
}	t_player;

typedef struct s_ray
{
	double		camera_x;
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		wall_dist;
	double		wall_x;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}	t_ray;

typedef struct s_display
{
	void			*mlx;
	void			*win;
	int				win_height;
	int				win_width;
	t_mapinfo		*mapinfo;
	t_player		*player;
	t_ray			*ray;
	t_texinfo		*texinfo;
	char			**map;
	int				**textures;
	int				**textures_pixels;
}	t_display;

typedef enum e_dir
{
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3,
}	t_dir;


#endif
