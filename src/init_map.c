/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ahunt@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:36:15 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/13 14:36:17 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_map	init_map(t_env *e, int x)
{
	t_map	map;

	map.camera_x = 2 * x / (double)WIDTH - 1;
	map.ray_dir_x = e->dir_x + e->plane_x * map.camera_x;
	map.ray_dir_y = e->dir_y + e->plane_y * map.camera_x;
	map.rpx = e->pos_x;
	map.rpy = e->pos_y;
	map.map_x = (int)map.rpx;
	map.map_y = (int)map.rpy;
	map.delta_y = delta_dist_y(map.ray_dir_y, map.ray_dir_x);
	map.delta_x = delta_dist_x(map.ray_dir_y, map.ray_dir_x);
	map.hit = 0;
	map.color = 0;
	return (map);
}
