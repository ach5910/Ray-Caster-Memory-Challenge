/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ach5910@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:59:11 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/12 10:59:19 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	rotate_view(t_env *e, double dir_x, double plane_x, int s)
{
	double oldDirY;
	double oldPlaneY;

	oldDirY = e->dirY;
	oldPlaneY = e->planeY;
	e->dirX = dir_x * cos(s * e->rot_speed) - oldDirY * sin(s * e->rot_speed);
	e->dirY = dir_x * sin(s * e->rot_speed) + oldDirY * cos(s * e->rot_speed);
	e->planeX = plane_x * cos(s * e->rot_speed)
		- oldPlaneY * sin(s * e->rot_speed);
	e->planeY = plane_x * sin(s * e->rot_speed)
		+ oldPlaneY * cos(s * e->rot_speed);
}
