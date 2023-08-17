/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:44:00 by datran            #+#    #+#             */
/*   Updated: 2023/08/16 18:22:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "cub3d.h"

# define WIN_HEIGHT	540
# define WIN_WIDTH	720

void	init_display_struct(t_display *display);
void	init_img_zero_struct(t_img *image);
void	init_gamewindow(t_display *display);
void	init_texture_struct(t_display *display, t_img *image, char *path);
void	init_img(t_display *display, t_img *image, int width, int height);
void	init_struct(t_display *display, char *filename);
void	init_map(t_display *display, char *filename);

#endif
