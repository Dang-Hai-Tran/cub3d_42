/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:44:00 by datran            #+#    #+#             */
/*   Updated: 2023/08/12 23:11:59 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "cub3d.h"
# define	WIN_HEIGHT	540
# define	WIN_WIDTH	720

typedef struct s_img t_img;
typedef struct s_text t_text;
typedef struct s_map t_map;
typedef struct s_ray t_ray;
typedef struct s_player t_player;
typedef struct s_display t_display;

void	init_display(t_display *display);
void	init_img_zero(t_img *image);
void	init_mlx(t_display *display);
void	init_texture(t_display *display, t_img *image, char *path);
void	init_img(t_display *display, t_img *image, int width, int height);

#endif
