/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture_buffer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ach5910@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:50:20 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/12 10:50:31 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	fill_texture_buffer(t_map map,t_env *e, int x)
{
	int d;
	int y;

	y = -1;
	while (++y < map.draw_end)
	{
		d = y * 256 - HEIGHT * 128 + map.line_height * 128;
		map.tex_y = ((d * TEXSIZE) / map.line_height) / 256;
		if (map.tex_num < 5 || (e->last_color == map.tex_num  && e->last_color > 4 && e->values[e->last_color - 5] < 0))
		{
			map.color = e->texture[map.tex_num][TEXSIZE * map.tex_y + map.tex_x];
		}
		else
			map.color = 0xFFFFFF;
		if (map.side == 1)
			map.color = (map.color >> 1) & 8355711;
		e->buffer[y][x] = map.color;
	}
}
