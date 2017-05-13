/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ach5910@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:57:55 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/12 10:58:01 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_map	get_texture_x(t_map map)
{
	map.tex_x = (int)(map.wallx * (double)(TEXSIZE));
	if (map.side == 0 && map.ray_dir_x > 0)
		map.tex_x = TEXSIZE - map.tex_x - 1;
	if (map.side == 1 && map.ray_dir_y < 0)
		map.tex_x = TEXSIZE - map.tex_x - 1;
	return (map);
}
