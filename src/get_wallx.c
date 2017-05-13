/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wallx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ach5910@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:56:20 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/12 10:56:32 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_map	get_wallx(t_map map)
{
	if (map.side == 0)
		map.wallx = map.rpy + map.perp_wall_dist * map.ray_dir_y;
	else
		map.wallx = map.rpx + map.perp_wall_dist * map.ray_dir_x;
	map.wallx -= floor((map.wallx));
	return (map);
}
