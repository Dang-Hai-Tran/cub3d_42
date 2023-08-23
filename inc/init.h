/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:44:00 by datran            #+#    #+#             */
/*   Updated: 2023/08/23 17:22:34 by datran           ###   ########.fr       */
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
typedef enum e_dir t_dir;
typedef enum e_code t_code;

void	init_display(t_display *display);
void	init_img_zero(t_img *image);
void	init_texture(t_display *display, t_img *image, char *path);
void	init_img(t_display *display, t_img *image, int width, int height);
void	init_player_dir(t_player *player);
void	init_texinfo(t_texinfo *texinfo);
void	init_mlx(t_display *display);
void	init_texbuffer(t_display *display);
void	init_ray(t_ray * ray);

#endif
