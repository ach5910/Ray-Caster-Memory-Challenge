/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_key_pressed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ach5910@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:05:24 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/12 11:05:36 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		my_key_pressed(int keycode, t_env *e)
{
	fps(e);
	if (keycode == 124)
		e->flags |= TRAN_H;
	else if (keycode == 123)
		e->flags |= TRAN_H | SIGN;
	else if (keycode == 126)
		e->flags |= TRAN_V;
	else if (keycode == 125)
		e->flags |= TRAN_V | SIGN;
	else if (keycode == 53)
		exit_hook(e);
	else if (keycode == 49)
	{
		if (e->game_state & START)
			e->game_state = PLAYING;
		else if (e->world_map[(int)(e->pos_x + e->dir_x)][(int)(e->pos_y
			+ e->dir_y)] != 0)
			check_for_match(e);
		if (e->game_state & PLAYING)
			redraw_game(e);
	}
	return (0);
}
