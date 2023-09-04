/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 23:25:40 by datran            #+#    #+#             */
/*   Updated: 2023/09/04 14:59:51 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include "cub3d.h"
# define MINIMAP_VIEW_DIST	4
# define MINIMAP_DISPLAY_SIZE 100
# define MINIMAP_DISPLAY_BORDER	5

typedef enum e_dir			t_dir;
typedef enum e_code			t_code;
typedef struct s_img		t_img;
typedef struct s_texinfo	t_texinfo;
typedef struct s_mapinfo	t_mapinfo;
typedef struct s_ray		t_ray;
typedef struct s_player		t_player;
typedef struct s_display	t_display;
typedef struct s_minimap	t_minimap;

void	set_image_pixel(t_img *image, int x, int y, int color);
void	init_texpixels(t_display *display);
void	perform_raycaster(t_display *display);
void	update_texpixels(t_display *display, t_texinfo *texinfo, \
t_ray *ray, int x);
void	render_images(t_display *display);
int		render_display(t_display *display);
char	**create_minimap_map(t_minimap *minimap, t_display *dp);
void	render_minimap_image(t_minimap *minimap, t_display *dp);
void	render_minimap(t_display *display);

#endif
