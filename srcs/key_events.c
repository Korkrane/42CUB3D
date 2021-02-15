/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:04:44 by bahaas            #+#    #+#             */
/*   Updated: 2021/02/15 03:11:19 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		key_pressed(int key, t_cub *cub)
{
	if (key == KEY_Z)
		cub->player.walk_d = 1;
	else if (key == KEY_S)
		cub->player.walk_d = -1;
	else if (key == KEY_LEFT)
		cub->player.turn_d = -1;
	else if (key == KEY_RIGHT)
		cub->player.turn_d = 1;
	else if (key == KEY_Q)
		cub->player.lateral_d = -1;
	else if (key == KEY_D)
		cub->player.lateral_d = 1;
	else if (key == KEY_ESC)
		end_cub(cub);
	update(cub, &cub->player);
	render(cub);
	return (0);
}

int		key_released(int key, t_player *player)
{
	if (key == KEY_Z || key == KEY_S)
		player->walk_d = 0;
	else if (key == KEY_LEFT || key == KEY_RIGHT)
		player->turn_d = 0;
	else if (key == KEY_Q || key == KEY_D)
		player->lateral_d = 0;
	return (0);
}
