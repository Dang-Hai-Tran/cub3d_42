/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 23:25:40 by datran            #+#    #+#             */
/*   Updated: 2023/08/20 09:47:38 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H
# include "cub3d.h"

typedef struct s_img t_img;
typedef struct s_texinfo t_texinfo;
typedef struct s_mapinfo t_mapinfo;
typedef struct s_ray t_ray;
typedef struct s_player t_player;
typedef struct s_display t_display;
typedef enum e_dir t_dir;

void	set_image_pixel(t_img *image, int x, int y, int color);
int		perform_raycaster(t_display *display);
void	update_texture_pixels(t_display *display, t_texinfo *texinfo, t_ray *ray, int x);


#endif
