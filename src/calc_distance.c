/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ach5910@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:51:23 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/12 10:51:43 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_map	calc_distances(t_env *e, t_map map)
{
	map.step_x = 1;
	map.side_dist_x = (map.mapX + 1.0 - e->posX) * map.delta_x;
	if (map.ray_dir_x < 0)
	{
		map.step_x = -1;
		map.side_dist_x = (e->posX - map.mapX) * map.delta_x;
	}
	map.step_y = 1;
	map.side_dist_y = (map.mapY + 1.0 - e->posY) * map.delta_y;
	if (map.ray_dir_y < 0)
	{
		map.step_y = -1;
		map.side_dist_y = (e->posY - map.mapY) * map.delta_y;
	}
	return (map);
}
