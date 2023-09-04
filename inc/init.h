/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:44:00 by datran            #+#    #+#             */
/*   Updated: 2023/09/04 14:57:11 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "cub3d.h"
# define WIN_HEIGHT	540
# define WIN_WIDTH	720
# define TEX_SIZE	64

# define MINIMAP_HEX_PLAYER		0xff0000
# define MINIMAP_HEX_FLOOR		0xffcc99
# define MINIMAP_HEX_WALL		0x33cc33
# define MINIMAP_HEX_SPACE		0x1a1a00
# define MINIMAP_HEX_BORDER		0x996633

typedef enum e_dir			t_dir;
typedef enum e_code			t_code;
typedef struct s_img		t_img;
typedef struct s_texinfo	t_texinfo;
typedef struct s_mapinfo	t_mapinfo;
typedef struct s_ray		t_ray;
typedef struct s_player		t_player;
typedef struct s_display	t_display;
typedef struct s_data		t_data;
typedef struct s_minimap	t_minimap;

// Bonus
typedef struct s_minimap
{
	char		**map;
	t_img		*image;
	int			size;
	int			offset_x;
	int			offset_y;
	int			view_dist;
	int			tile_size;
	unsigned long		hex_player;
	unsigned long		hex_floor;
	unsigned long		hex_wall;
	unsigned long		hex_space;
	unsigned long		hex_border;
}		t_minimap;

unsigned long	convert_rgb_to_hex(int *rgb);
int		*get_arr_rgb(int r, int g, int b);
void	init_display(t_display *display, t_data *data);
void	init_img_zero(t_img *image);
void	init_texture(t_display *display, t_img *image, char *path);
void	init_img(t_display *display, t_img *image, int width, int height);
void	init_player_dir(t_player *player);
void	init_mlx(t_display *display);
void	init_texbuffer(t_display *display);
void	init_ray(t_ray *ray);
void	init_minimap(t_minimap *minimap, t_display *display);

#endif
