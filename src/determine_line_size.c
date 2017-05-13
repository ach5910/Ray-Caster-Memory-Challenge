/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_line_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ach5910@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:47:10 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/12 10:47:25 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_map	determine_line_size(t_map map)
{
	map.line_height = (int)(HEIGHT / map.perp_wall_dist);
	map.draw_start = -map.line_height / 2 + HEIGHT / 2;
	if(map.draw_start < 0)
		map.draw_start = 0;
	map.draw_end = map.line_height / 2 + HEIGHT / 2;
	if(map.draw_end >= HEIGHT)
		map.draw_end = HEIGHT - 1;
	return (map);
}
