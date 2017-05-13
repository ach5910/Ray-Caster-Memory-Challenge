/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ach5910@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:59:55 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/12 11:00:02 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	move_player(t_env *e, int s)
{
	if (e->world_map[(int)((e->pos_x) + s * e->dir_x *
		e->move_speed)][(int)(e->pos_y)] == 0)
		e->pos_x = e->pos_x + s * e->dir_x * e->move_speed;
	if (e->world_map[(int)(e->pos_x)][(int)((e->pos_y) + s *
		e->dir_y * e->move_speed)] == 0)
		e->pos_y = e->pos_y + s * e->dir_y * e->move_speed;
}
