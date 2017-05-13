/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_match.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ahunt@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:33:01 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/13 14:33:03 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	check_for_match(t_env *e)
{
	int cur_col;

	cur_col = e->world_map[(int)(e->pos_x +
		e->dir_x)][(int)(e->pos_y + e->dir_y)];
	if (cur_col > 4 && (cur_col - 5) % 8 == (e->last_color - 5) %
		8 && cur_col != e->last_color)
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
