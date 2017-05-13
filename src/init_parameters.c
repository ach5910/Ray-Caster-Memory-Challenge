/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parameters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ahunt@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:37:04 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/13 14:37:06 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_env	*init_parameters(t_env *e)
{
	e->pos_x = 12;
	e->pos_y = 12;
	e->dir_x = -1;
	e->dir_y = 0;
	e->plane_x = 0;
	e->plane_y = 0.66;
	e->rot_speed = 0.016666 * 1.25;
	e->move_speed = 0.016666 * 3;
	e->fps = 0.0f;
	e->last_color = 0;
	e->time = 100;
	e->blocks = 16;
	e->time_left = 20;
	e->game_state = START;
	e->values = init_box_states();
	e->texture = set_textures();
	e = init_grid(e);
	return (e);
}
