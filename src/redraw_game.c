/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ach5910@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:00:47 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/12 11:01:00 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		redraw_game(t_env *e)
{
	t_map map;
	int x;

	x = -1;
	while (++x < WIDTH)
	{
		map = init_map(e, x);
		map = calc_distances(e, map);
		while (map.hit == 0)
			map = check_if_hit(map, e);
		map.perp_wall_dist = determine_wall_distance(e, map);
		map = determine_line_size(map);
		map.tex_num = e->world_map[map.mapX][map.mapY];
		if (map.tex_num > 4 && e->values[map.tex_num - 5] == 0)
			e->world_map[map.mapX][map.mapY] = 0;
		map = get_wallx(map);
		map = get_texture_x(map);
		fill_texture_buffer(map, e, x);
		map = floor_casting(map);
		map.dist_wall = map.perp_wall_dist;
		map.dist_player = 0.0;
		map.draw_end = map.draw_end < 0 ? HEIGHT : map.draw_end;
		draw_floor(map, e, x);
	}
	draw_map(e, map);
	return (0);
}
