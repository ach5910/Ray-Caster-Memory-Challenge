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
	double old_dir_y;
	double old_plane_y;

	old_dir_y = e->dir_y;
	old_plane_y = e->plane_y;
	e->dir_x = dir_x * cos(s * e->rot_speed) -
		old_dir_y * sin(s * e->rot_speed);
	e->dir_y = dir_x * sin(s * e->rot_speed) +
		old_dir_y * cos(s * e->rot_speed);
	e->plane_x = plane_x * cos(s * e->rot_speed)
		- old_plane_y * sin(s * e->rot_speed);
	e->plane_y = plane_x * sin(s * e->rot_speed)
		+ old_plane_y * cos(s * e->rot_speed);
}
