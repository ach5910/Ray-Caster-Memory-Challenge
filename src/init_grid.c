/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ach5910@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:15:03 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/12 10:15:26 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_env	*init_grid(t_env *e)
{
	int i;
	int j;

	e->world_map = (int**)malloc(sizeof(int*) * mapWidth + 1);
	i = -1;
	while (++i < mapWidth)
	{
		e->world_map[i] = (int*)malloc(sizeof(int) * mapHeight + 1);
		j = -1;
		while (++j < mapHeight)
		{
			if (i == 0)
				e->world_map[i][j] = 2;
			else if (i == 23)
				e->world_map[i][j] = 3;
			else if (j == 0)
				e->world_map[i][j] = 1;
			else if (j == 23)
				e->world_map[i][j] = 4;
			else
				e->world_map[i][j] = 0;
		}
	}
	e->world_map[4][4] = 5;
	e->world_map[4][9] = 9;
	e->world_map[4][14] = 17;
	e->world_map[4][19] = 14;
	e->world_map[9][4] = 6;
	e->world_map[9][9] = 10;
	e->world_map[9][14] = 13;
	e->world_map[9][19] = 15;
	e->world_map[14][4] = 7;
	e->world_map[14][9] = 11;
	e->world_map[14][14] = 16;
	e->world_map[14][19] = 20;
	e->world_map[19][4] = 8;
	e->world_map[19][9] = 12;
	e->world_map[19][14] = 19;
	e->world_map[19][19] = 18;
	return (e);

}
