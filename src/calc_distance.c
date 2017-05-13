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
	map.side_dist_x = (map.map_x + 1.0 - e->pos_x) * map.delta_x;
	if (map.ray_dir_x < 0)
	{
		map.step_x = -1;
		map.side_dist_x = (e->pos_x - map.map_x) * map.delta_x;
	}
	map.step_y = 1;
	map.side_dist_y = (map.map_y + 1.0 - e->pos_y) * map.delta_y;
	if (map.ray_dir_y < 0)
	{
		map.step_y = -1;
		map.side_dist_y = (e->pos_y - map.map_y) * map.delta_y;
	}
	return (map);
}
