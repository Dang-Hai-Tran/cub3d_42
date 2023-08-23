/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 22:20:34 by datran            #+#    #+#             */
/*   Updated: 2023/08/23 09:21:22 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_raycaster(int x, t_ray *ray, t_player *player)
{
	init_ray(ray);
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	if (ray->dir_x != 0)
		ray->deltadist_x = fabs(1 / ray->dir_x);
	else
		ray->deltadist_x = (double)1e30;
	if (ray->dir_y != 0)
		ray->deltadist_y = fabs(1 / ray->dir_y);
	else
		ray->deltadist_y = (double)1e30;
}

static void	setup_dda_algo(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1 - player->pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_x = (ray->map_y + 1 - player->pos_y) * ray->deltadist_y;
	}
}

static void	perform_dda_algo(t_display *display, t_ray *ray)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25 || ray->map_x < 0.25 || ray->map_y > display->mapinfo->height - 0.25 || ray->map_x > display->mapinfo->width - 0.25)
			break ;
		if (display->map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

static void calculate_line_height(t_ray *ray, t_display *display, t_player *player)
{
	if (ray->side == 0)
		ray->wall_dist = ray->sidedist_x - ray->deltadist_x;
	else
		ray->wall_dist = ray->sidedist_y - ray->deltadist_y;
	ray->line_height = (int)display->win_height / ray->wall_dist;
	ray->draw_start = -(ray->line_height / 2) + display->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + display->win_height / 2;
	if (ray->draw_end >= display->win_height)
		ray->draw_end = display->win_height - 1;
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	perform_raycaster(t_display *display)
{
	t_ray		*ray;
	t_player	*player;
	int			x;

	x = 0;
	ray = display->ray;
	player = display->player;
	while (x < display->win_width)
	{
		init_raycaster(x, ray, player);
		setup_dda_algo(ray, player);
		perform_dda_algo(display, ray);
		calculate_line_height(ray, display, player);
		update_texpixels(display, display->texinfo, display->ray, x);
		x++;
	}
}
