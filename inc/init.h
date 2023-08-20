/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:44:00 by datran            #+#    #+#             */
/*   Updated: 2023/08/20 10:30:31 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "cub3d.h"
# define	WIN_HEIGHT	540
# define	WIN_WIDTH	720
# define	TEX_SIZE	64

typedef struct s_img t_img;
typedef struct s_texinfo t_texinfo;
typedef struct s_mapinfo t_mapinfo;
typedef struct s_ray t_ray;
typedef struct s_player t_player;
typedef struct s_display t_display;

void	init_display_struct(t_display *display);
void	init_img_zero_struct(t_img *image);
void	init_gamewindow(t_display *display);
void	init_texture_struct(t_display *display, t_img *image, char *path);
void	init_img(t_display *display, t_img *image, int width, int height);
void	init_player_dir(t_player *player);
void	init_texinfo(t_texinfo *texinfo);
void	init_textures(t_display *display);
void	init_ray(t_ray * ray);
void	init_struct(t_display *display, char *filename);
void	init_map(t_display *display, char *filename);

#endif
