/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta_dist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ahunt@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:35:30 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/13 14:35:32 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

double	delta_dist_y(double ray_dir_y, double ray_dir_x)
{
	return (sqrt(1 + (ray_dir_x * ray_dir_x) / (ray_dir_y * ray_dir_y)));
}

double	delta_dist_x(double ray_dir_y, double ray_dir_x)
{
	return (sqrt(1 + (ray_dir_y * ray_dir_y) / (ray_dir_x * ray_dir_x)));
}
