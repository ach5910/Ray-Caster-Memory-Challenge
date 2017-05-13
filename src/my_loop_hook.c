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
	printf("pasting not playing\n");
	if ((e->blocks < 2 || e->time_left < 1))
	{
		e->game_state = GAMEOVER;
		D_TIMER(stop)(&e->timer);
		// free_environment(e);
		draw_game_over(e);
	}
	if (e->fps >= 1 / 60.0f)
	{
		if (e->fps > 0.025)
			e->fps = 0.025;
		e->move_speed = e->fps  * 12.0; //the constant value is in squares/second
		e->rot_speed = e->fps * ((double)M_PI / 1.1); //the constant value is in radians/second
	}
	if (e->flags & SIGN)
	{
		if (e->flags & TRAN_V)
			move_player(e, -1);
		else if (e->flags & TRAN_H)
			rotate_view(e, e->dirX, e->planeX, 1);
	}
	else if (e->flags & TRAN_V)
		move_player(e, 1);
	else if (e->flags & TRAN_H)
		rotate_view(e, e->dirX, e->planeX, -1);
	if (e->flags)
	{
		e->flags = 0;
		redraw_game(e);
	}
	else
		update_timer(e);
	return (0);
}
