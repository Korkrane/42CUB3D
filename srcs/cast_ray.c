/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:50:16 by bahaas            #+#    #+#             */
/*   Updated: 2021/01/27 23:55:35 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_ray	cast(t_ray ray, t_cub3d *cub3d)
{
	float		hz_dist;
	float		vt_dist;
	t_line		line;
	t_coord		wall_hit;

	hz_cast(&ray, cub3d);
	vt_cast(&ray, cub3d);
	hz_dist = FLT_MAX;
	vt_dist = FLT_MAX;
	if(ray.found_hz_wall)
		hz_dist = p_dist(cub3d->player.pos.x, cub3d->player.pos.y,
				ray.hz_hit.x, ray.hz_hit.y);
	if(ray.found_vt_wall)
		vt_dist = p_dist(cub3d->player.pos.x, cub3d->player.pos.y,
				ray.vt_hit.x, ray.vt_hit.y);
	//printf("vt_hitx = %f\n", ray.vt_hit.x);
	//printf("vt_hity = %f\n", ray.vt_hit.y);
	//printf("vt_dist = %f\n", vt_dist);
	//printf("found_vt_wall = %d\n", ray.found_vt_wall);
	//printf("hz_dist = %f\n", hz_dist);
	ray.wall_hit_x = (hz_dist < vt_dist) ? ray.hz_hit.x : ray.vt_hit.x;
	ray.wall_hit_y = (hz_dist < vt_dist) ? ray.hz_hit.y : ray.vt_hit.y;
	ray.distance = (hz_dist < vt_dist) ? hz_dist : vt_dist;
	ray.was_vt_hit = (vt_dist < hz_dist);
	wall_hit = init_coord(ray.wall_hit_x, ray.wall_hit_y);
	//printf("wall hit x = %f\n", wall_hit.x);
	//printf("wall hit y = %f\n", wall_hit.y);
	line = init_line(cub3d->player.pos, wall_hit);
//	render_view_line(&line, cub3d, GREEN);
	return(ray);
}

t_ray *cast_all_rays(t_cub3d *cub3d)
{
	t_ray	*rays;
	float	ray_ang;
	int i;

	i = 0;
	rays = malloc(sizeof(t_ray) * NUM_RAYS);
	if(!rays)
		return 0;
	//ray_ang = cub3d->player.rot_ang - (FOV / 2);
	
	int num = NUM_RAYS;
	
//	printf("num: %d\n", num);
//	printf("NUM_RAYS: %d\n", NUM_RAYS);
/*
	printf("ray incr: %f\n", (FOV / (int)NUM_RAYS));
	printf("ray incr: %f\n", (FOV / 480));
	printf("ray incr: %f\n", (FOV / num));
	*/
	while(i < NUM_RAYS)
	{
		ray_ang = cub3d->player.rot_ang + atan((i - NUM_RAYS / 2) / DIST_PROJ_PLANE);
		rays[i].ray_ang = normalize(ray_ang);
		init_ray(&rays[i], rays[i].ray_ang);
		rays[i] = cast(rays[i], cub3d);
		//ray_ang = ray_ang + (FOV / num);
		i++;
	}
	return(rays);
}