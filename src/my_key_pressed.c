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
		e->flags |= TRAN_V ;
	else if (keycode == 125)
		e->flags |= TRAN_V | SIGN;
	else if (keycode == 53)
	{
		free_environment(e);
		free_image(e);
		ft_memdel((void **)&e);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 49 && e->world_map[(int)(e->posX + e->dirX)][(int)(e->posY + e->dirY)] != 0)
	{
		int cur_col = e->world_map[(int)(e->posX + e->dirX)][(int)(e->posY + e->dirY)];
		if (cur_col > 4 && (cur_col - 5) % 8 == (e->last_color - 5) % 8 && cur_col != e->last_color)
		{
			e->values[cur_col - 5] = 0;
			e->values[e->last_color - 5] = 0;
			e->last_color = 0;
			e->timer += 15;
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
		redraw_game(e);
	}

	return (0);
}
