/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_timer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ach5910@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:25:36 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/12 14:25:49 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	clear_timer_box(t_env *e)
{
	int x;
	int y;

	x = 744;
	while (++x < 790)
	{
		y = 24;
		while (++y < 50)
			mlx_pixel_put(e->mlx, e->win, x, y, 0);
	}
}

void	update_timer(t_env *e)
{
	int		ticks;
	char	*tmp;

	if (is_started(&e->timer) == 0)
		timer_start(&e->timer);
	ticks = (int)(get_ticks(&e->timer) / 1000);
	clear_timer_box(e);
	e->time_left = e->time - ticks;
	tmp = ft_itoa_base((size_t)(e->time_left), 10, 1);
	mlx_string_put(e->mlx, e->win, 750, 25, 16777215, tmp);
	ft_memdel((void **)&tmp);
	if (e->time_left < 1)
		draw_game_over(e);
}
