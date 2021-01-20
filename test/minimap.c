/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:58:31 by bahaas            #+#    #+#             */
/*   Updated: 2021/01/20 09:40:07 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;

	if( x >= 0 && x <= WIN_WID  && y >= 0 && y <= WIN_HEI)
	{
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void	render_minimap_square(int x, int y, int size, t_cub3d *cub3d)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(&cub3d->img, x + j, y + i, GRAY);
			j++;
		}
		i++;
	}
}

/*
**	Bresenham line algorithm
*/ 

void	render_view_line(t_line *line, t_cub3d *cub3d, int color)
{
/*
	int e2;
	float dx =  abs(line->end.x -line->start.x);
	float sx = line->start.x < line->end.x ? 1 : -1;
	float dy = -abs(line->end.y - line->start.y);
	float sy = line->start.y < line->end.y ? 1 : -1;
	float err = dx+dy;
	while (1) 
	{
		my_mlx_pixel_put(&cub3d->img, line->start.x + cub3d->player.radius / 2, line->start.y + cub3d->player.radius / 2, color);
		if (line->start.x == line->end.x && line->start.y == line->end.y)
			break ;
		e2 = 2*err;
		if (e2 >= dy)
		{
			err += dy;
			line->start.x += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			line->start.y += sy;
		}
	}	
	*/
		
	   float t;
	   float x; 
	   float y;

	   t = 0;
	   while(t < 1)
	   {
	   x = line->start.x + (line->end.x - line->start.x)*t;
	   y = line->start.y + (line->end.y - line->start.y)*t;
	   my_mlx_pixel_put(&cub3d->img, x + cub3d->player.radius / 2, y + cub3d->player.radius / 2, color);
	   t += 0.01;
	   }
}

void	render_player(t_cub3d *cub3d)
{
	t_line line;

	line.start.x = 0;
	line.start.y = 0;
	line.start.x += cub3d->player.pos.x;
	line.start.y += cub3d->player.pos.y;
	line.end.y = line.start.y + sin(cub3d->player.rot_ang) * 120;
	line.end.x = line.start.x + cos(cub3d->player.rot_ang) * 120;

	render_minimap_square(line.start.x, line.start.y, cub3d->player.radius, cub3d);
	render_view_line(&line, cub3d, WHITE);
}

void	render_ray(t_cub3d *cub3d, t_ray ray)
{
	t_line line;

	line.start.x = 0;
	line.start.y = 0;
	line.start.x += cub3d->player.pos.x;
	line.start.y += cub3d->player.pos.y;
	line.end.y = line.start.y + sin(ray.ray_ang) * 30;
	line.end.x = line.start.x + cos(ray.ray_ang) * 30;
	render_view_line(&line, cub3d, BLUE);
	return ;
}

