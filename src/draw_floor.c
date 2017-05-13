/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ach5910@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:55:19 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/12 10:55:33 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_floor(t_map map,t_env *e, int x)
{
	int y;
	double cur_fl_x;
	double cur_fl_y;
	int fl_tx_x;
	int	fl_tx_y;

	y = map.draw_end;
	while (++y < HEIGHT)
	{
		map.cur_dist = HEIGHT / (2.0 * y - HEIGHT);
		map.weight = (map.cur_dist - map.dist_player) / (map.dist_wall - map.dist_player);
		cur_fl_x = map.weight * map.floor_x_wall + (1.0 - map.weight) * e->posX;
		cur_fl_y = map.weight * map.floor_y_wall + (1.0 - map.weight) * e->posY;
		fl_tx_x = (int)(cur_fl_x * TEXSIZE) % TEXSIZE;
		fl_tx_y = (int)(cur_fl_y * TEXSIZE) % TEXSIZE;
		e->buffer[y][x] = (e->texture[0][TEXSIZE * fl_tx_y + fl_tx_x] >> 1) & 8355711;
		e->buffer[(HEIGHT - y)][  x] = (e->texture[0][TEXSIZE * fl_tx_y + fl_tx_x]);
	}
}
