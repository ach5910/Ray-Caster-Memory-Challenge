/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ach5910@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 18:47:41 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/12 18:47:55 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	fps(t_env *e)
{
	static clock_t start = 0;
	static clock_t end = 0;

	start = end;
	end = clock();
	e->fps = (double)(end - start) / CLOCKS_PER_SEC;
	if (e->fps >= 1 / 60.0f)
	{
		if (e->fps > 0.03)
			e->fps = 0.03;
		e->move_speed = e->fps * 20.0;
		e->rot_speed = e->fps * ((double)M_PI / 0.75);
	}
}
