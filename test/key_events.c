/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:04:44 by bahaas            #+#    #+#             */
/*   Updated: 2021/01/14 02:14:02 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_pressed(int keycode, t_cub3d *cub3d)
{
	if (keycode == 'z' || keycode == KEY_W)
	{
		cub3d->player.walk_d = 1;
		printf("keycode : %d\n", keycode);
		printf("walk_direction : %d\n", cub3d->player.walk_d);
	}
	else if (keycode == 's')
	{
		cub3d->player.walk_d = -1;
		printf("keycode : %d\n", keycode);
		printf("walk_direction : %d\n", cub3d->player.walk_d);
	}
	if (keycode == 'q' || keycode == KEY_A)
	{
		cub3d->player.turn_d = -1;
		printf("keycode : %d\n", keycode);
		printf("walk_d : %d\n", cub3d->player.turn_d);
	}
	if (keycode == 'd')
	{
		cub3d->player.turn_d = 1;
		printf("keycode : %d\n", keycode);
		printf("walk_d : %d\n", cub3d->player.turn_d);
	}
	update(cub3d);
}

int		key_released(int keycode, t_player *player)
{
	if (keycode == 'z' || keycode == KEY_W)
	{
		player->walk_d = 0;
		printf("keycode : %d\n", keycode);
		printf("walk_d : %d\n", player->walk_d);
	}
	else if (keycode == 's')
	{
		player->walk_d = 0;
		printf("keycode : %d\n", keycode);
		printf("walk_d : %d\n", player->walk_d);
	}
	if (keycode == 'q' || keycode == KEY_A)
	{
		player->turn_d = 0;
		printf("keycode : %d\n", keycode);
		printf("walk_d : %d\n", player->turn_d);
	}
	if (keycode == 'd')
	{
		player->turn_d = 0;
		printf("keycode : %d\n", keycode);
		printf("walk_d : %d\n", player->turn_d);
	}
}