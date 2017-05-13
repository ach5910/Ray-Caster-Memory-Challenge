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
		//printf("after init\n");
		map = calc_distances(e, map);
		// printf("after calc\n");
		while (map.hit == 0)
			map = check_if_hit(map, e);
		// printf("after if hit\n");
		map.perp_wall_dist = determine_wall_distance(e, map);
		// printf("after determine_wall_distance\n");
		map = determine_line_size(map);
		// printf("after determine_line_size\n");
		map.tex_num = e->world_map[map.mapX][map.mapY];
		if (map.tex_num > 4 && e->values[map.tex_num - 5] == 0)
			e->world_map[map.mapX][map.mapY] = 0;
		// printf("after if\n");
		map = get_wallx(map);
		// printf("after get_wallx\n");
		map = get_texture_x(map);
		// printf("after get_texture_x\n");
		fill_texture_buffer(map, e, x);
		// printf("after fill_texture_buffer\n");
		map = floor_casting(map);
		// printf("after floor casting\n");
		map.dist_wall = map.perp_wall_dist;
		map.dist_player = 0.0;
		if (map.draw_end < 0)
			map.draw_end = HEIGHT;
		draw_floor(map, e, x);
		buffer_to_image(e, x);
	}
	clear_buffer(e);
	draw_map(e, map);
	return (0);
}
