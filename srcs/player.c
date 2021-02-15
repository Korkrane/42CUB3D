/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:13:53 by bahaas            #+#    #+#             */
/*   Updated: 2021/02/15 03:08:53 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_player(t_player *player)
{
	player->pos.x = -1;
	player->pos.y = -1;
	player->radius = 6;
	player->turn_d = 0;
	player->walk_d = 0;
	player->lateral_d = 0;
	player->rot_ang = 0;
	player->mov_speed = 0.3;
	player->rot_speed = 3 * (M_PI / 180);
}
/*
void	update(t_cub *cub)
{
	float mov_step;
	float lateral_angle;
	float new_x;
	float new_y;

	cub->player.rot_ang += cub->player.turn_d * cub->player.rot_speed;
	cub->player.rot_ang = normalize(cub->player.rot_ang);
	mov_step = cub->player.walk_d * cub->player.mov_speed;
	new_player_x = cub->player.pos.x + cos(cub->player.rot_ang) * mov_step;
	new_y = cub->player.pos.y + sin(cub->player.rot_ang) * mov_step;
	if (cub->player.lateral_d != 0)
	{
		lateral_angle = cub->player.rot_ang + ((M_PI / 2) * cub->player.lateral_d);
		new_player_x = cub->player.pos.x + cos(lateral_angle) * cub->player.mov_speed;
		new_y = cub->player.pos.y + sin(lateral_angle) * cub->player.mov_speed;
	}
	if (!grid_is_wall(new_player_x, new_y, cub))
	{
		cub->player.pos.x = new_player_x;
		cub->player.pos.y = new_y;
	}
}*/

void	update(t_cub *cub, t_player *player)
{
	float mov_step;
	float lateral_ang;
	float new_x;
	float new_y;

	player->rot_ang += player->turn_d * player->rot_speed;
	player->rot_ang = normalize(player->rot_ang);
	mov_step = player->walk_d * player->mov_speed;
	new_x = player->pos.x + cos(player->rot_ang) * mov_step;
	new_y = player->pos.y + sin(player->rot_ang) * mov_step;
	if (player->lateral_d != 0)
	{
		lateral_ang = player->rot_ang + ((M_PI / 2) * player->lateral_d);
		new_x = player->pos.x + cos(lateral_ang) * player->mov_speed;
		new_y = player->pos.y + sin(lateral_ang) * player->mov_speed;
	}
	if (!grid_is_wall(new_x, new_y, cub))
	{
		cub->player.pos.x = new_x;
		cub->player.pos.y = new_y;
	}
}

void	pos_player(t_player *player, int x, int y, char orientation)
{
	if (player->pos.x == -1 && player->pos.y == -1)
	{
		player->pos.x = x + 0.001;
		player->pos.y = y + 0.001;
		if (orientation == 'N')
			player->rot_ang = 1.5 * M_PI;
		else if (orientation == 'S')
			player->rot_ang = M_PI / 2;
		else if (orientation == 'E')
			player->rot_ang = 0;
		else if (orientation == 'W')
			player->rot_ang = M_PI;
	}
}

int		check_player(t_cub *cub)
{
	int x;
	int y;
	int num_position;

	y = -1;
	num_position = 0;
	while (++y < cub->data.rows)
	{
		x = -1;
		while (cub->grid[y][++x])
		{
			if (ft_strchr("NSEW", cub->grid[y][x]))
			{
				pos_player(&cub->player, x, y, cub->grid[y][x]);
				num_position++;
				cub->grid[y][x] = '0';
				if (num_position > 1)
					return (is_error("Multiple player position in map"));
			}
		}
	}
	if (num_position == 0)
		return (is_error("No player position in map"));
	printf("player OK\n");
	return (1);
}
