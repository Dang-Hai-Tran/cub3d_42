/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 23:25:36 by datran            #+#    #+#             */
/*   Updated: 2023/08/28 16:44:52 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

# include "cub3d.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef enum e_dir			t_dir;
typedef enum e_code			t_code;
typedef struct s_img		t_img;
typedef struct s_texinfo	t_texinfo;
typedef struct s_mapinfo	t_mapinfo;
typedef struct s_ray		t_ray;
typedef struct s_player		t_player;
typedef struct s_display	t_display;

# define MOVE_SPEED 0.01
# define ROTATE_SPEED 0.01

void	input_listen(t_display *display);
int		check_move(t_display *display, double npos_x, double npos_y);
int		player_rotate(t_display *display);
int		player_move(t_display *display);

#endif
