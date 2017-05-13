/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_match.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 06:19:17 by                   #+#    #+#             */
/*   Updated: 2017/05/13 06:19:39 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	check_for_match(t_env *e)
{
	int cur_col;

	cur_col = e->world_map[(int)(e->posX + e->dirX)][(int)(e->posY + e->dirY)];
	if (cur_col > 4 && (cur_col - 5) % 8 == (e->last_color - 5) % 8 && cur_col != e->last_color)
	{
		e->values[cur_col - 5] = 0;
		e->values[e->last_color - 5] = 0;
		e->last_color = 0;
		e->time += 15;
		e->blocks -= 2;
	}
	else if (e->last_color != 0)
	{
		e->values[e->last_color - 5] = 1;
		e->last_color = 0;
	}
	else
	{
		e->values[cur_col - 5] = -1;
		e->last_color = cur_col;
	}
}
