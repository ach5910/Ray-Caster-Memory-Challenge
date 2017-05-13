/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_loop_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ach5910@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:04:31 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/12 11:04:41 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		my_loop_hook(t_env *e)
{
	if (e->game_state != PLAYING)
		return (0);
	if ((e->blocks < 2 || e->time_left < 1))
		draw_game_over(e);
	if (e->flags & SIGN)
	{
		if (e->flags & TRAN_V)
			move_player(e, -1);
		else if (e->flags & TRAN_H)
			rotate_view(e, e->dir_x, e->plane_x, 1);
	}
	else if (e->flags & TRAN_V)
		move_player(e, 1);
	else if (e->flags & TRAN_H)
		rotate_view(e, e->dir_x, e->plane_x, -1);
	if (e->flags)
	{
		e->flags = 0;
		redraw_game(e);
	}
	else
		update_timer(e);
	return (0);
}
