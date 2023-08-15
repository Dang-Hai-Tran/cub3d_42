/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:44:00 by datran            #+#    #+#             */
/*   Updated: 2023/08/15 11:28:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

#include "cub3d.h"

# define	WIN_HEIGHT	540
# define	WIN_WIDTH	720

typedef struct s_img t_img;
typedef struct s_text t_text;
typedef struct s_map t_map;
typedef struct s_player t_player;
typedef struct s_ray t_ray;
typedef struct s_display t_display;

void	init_display_struct(t_display *display);
void	init_img_zero_struct(t_img *image);
void	init_gamewindow(t_display *display);
void	init_texture_struct(t_display *display, t_img *image, char *path);
void	init_img(t_display *display, t_img *image, int width, int height);
void	init_struct(t_display *display, char *filename);
void	init_map(t_display *display, char *filename);

#endif
