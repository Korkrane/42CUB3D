/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 01:12:44 by bahaas            #+#    #+#             */
/*   Updated: 2021/01/22 12:51:18 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_map *map)
{
	map->cols = 0;
	map->rows = 0;
}

void	init_player(t_player *player)
{
	player->pos.x = WIN_WID / 2;
	player->pos.y = WIN_HEI / 2;
	player->radius = 6;
	player->turn_d = 0;
	player->walk_d = 0;
	player->rot_ang = M_PI / 2;
	player->mov_speed = 2.0;
	player->rot_speed = 1 * (M_PI / 180);
}

void	init_img(t_img *img, t_win *win)
{
	img->img = mlx_new_image(win->mlx_p, WIN_WID, WIN_HEI);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	init_win(t_win *win)
{
	win->mlx_p = NULL;
	win->win_p = NULL;
}

void init_ray(t_ray *ray, float ray_ang)
{
	ray->ray_ang = ray_ang;
	//printf("ray_ang init : %f\n\n", ray->ray_ang);
	ray->wall_hit_x = 0;
	ray->wall_hit_y = 0;
	ray->distance = 0;
	ray->was_vt_hit = FALSE;
	ray->facing_down = ray_ang > 0 && ray_ang < M_PI;
	ray->facing_up = !ray->facing_down;
	ray->facing_right = ray_ang < 0.5 * M_PI || ray_ang > 1.5 * M_PI;
	ray->facing_left = !ray->facing_right;
}

/*
void init_ray(t_ray ray, float ray_ang)
{
	ray.ray_ang = ray_ang;
	//printf("ray_ang init : %f\n\n", ray.ray_ang);
	ray.wall_hit_x = 0;
	ray.wall_hit_y = 0;
	ray.distance = 0;
	ray.was_vt_hit = FALSE;
	ray.facing_down = ray_ang > 0 && ray_ang < M_PI;
	ray.facing_up = !ray.facing_down;
	ray.facing_right = ray_ang < 0.5 * M_PI || ray_ang > 1.5 * M_PI;
	ray.facing_left = !ray.facing_right;
}
*/
