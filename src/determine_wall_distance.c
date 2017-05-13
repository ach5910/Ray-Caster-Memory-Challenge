/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_wall_distance.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ach5910@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:49:09 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/12 10:49:23 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

double	determine_wall_distance(t_env *e, t_map map)
{
	if (map.side == 0)
		return ((map.mapX - map.rpx + (1 - map.step_x) / 2) / map.ray_dir_x);
	else
		return ((map.mapY - map.rpy + (1 - map.step_y) / 2) / map.ray_dir_y);
}
