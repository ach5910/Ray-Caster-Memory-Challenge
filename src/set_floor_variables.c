/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_floor_variables.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ahunt@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:44:40 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/13 14:44:53 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_map	set_floor_variables(t_map map)
{
	map.dist_wall = map.perp_wall_dist;
	map.dist_player = 0.0;
	map.draw_end = map.draw_end < 0 ? HEIGHT : map.draw_end;
	return (map);
}
