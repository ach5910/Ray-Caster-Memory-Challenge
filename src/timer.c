/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ahunt@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:40:36 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/13 14:40:38 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		is_started(t_timer *t)
{
	return (t->started == 1);
}

void	timer_start(t_timer *t)
{
	t->started = 1;
	gettimeofday(&t->start, NULL);
}

size_t	get_ticks(t_timer *t)
{
	struct timeval	tmp;

	if (t->started == 0)
		return (0);
	gettimeofday(&tmp, NULL);
	return (((size_t)tmp.tv_sec * 1000 + (size_t)tmp.tv_usec / 1000) -
	((size_t)t->start.tv_sec * 1000 +
	(size_t)t->start.tv_usec / 1000));
}
