/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_hit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ach5910@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:18:37 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/12 10:46:05 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_map	check_if_hit(t_map map, t_env *e)
{
	if (map.side_dist_x < map.side_dist_y)
	{
		map.side_dist_x += map.delta_x;
		map.map_x += map.step_x;
		map.side = 0;
	}
	else
	{
		map.side_dist_y += map.delta_y;
		map.map_y += map.step_y;
		map.side = 1;
	}
	if (e->world_map[map.map_x][map.map_y] > 0)
		map.hit = 1;
	return (map);
}
