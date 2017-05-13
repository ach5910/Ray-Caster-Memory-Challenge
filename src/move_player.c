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
	if(e->world_map[(int)((e->posX) + s * e->dirX * e->move_speed)][(int)(e->posY)] == 0)
		e->posX = e->posX + s * e->dirX * e->move_speed;
	if(e->world_map[(int)(e->posX)][(int)((e->posY) + s * e->dirY * e->move_speed)] == 0)
		e->posY = e->posY + s * e->dirY * e->move_speed;
}
