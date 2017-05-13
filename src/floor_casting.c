/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ach5910@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:52:30 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/12 10:52:45 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_map	floor_casting(t_map map)
{
	if (map.side == 0 && map.ray_dir_x > 0)
	{
		map.floor_x_wall = map.mapX;
		map.floor_y_wall = map.mapY + map.wallx;
	}
	else if (map.side == 0 && map.ray_dir_x < 0)
	{
		map.floor_x_wall = map.mapX + 1.0;
		map.floor_y_wall = map.mapY + map.wallx;
	}
	else if (map.side == 1 && map.ray_dir_y > 0)
	{
		map.floor_x_wall = map.mapX + map.wallx;
		map.floor_y_wall = map.mapY;
	}
	else
	{
		map.floor_x_wall = map.mapX + map.wallx;
		map.floor_y_wall = map.mapY + 1.0;
	}
	return (map);
}
