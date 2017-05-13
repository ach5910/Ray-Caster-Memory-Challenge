/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomize_boxes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ahunt@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:38:48 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/13 14:38:49 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		fib(int i)
{
	return (i < 2 ? 1 : fib(i - 1) + fib(i - 2));
}

int		*randomize_boxes(void)
{
	int		*temp;
	int		i;
	int		c1;
	t_timer	t;
	size_t	ticks;

	temp = (int*)malloc(sizeof(int) * 16);
	timer_start(&t);
	i = -1;
	while (++i < 16)
		temp[i] = i + 5;
	i = -1;
	while (++i < 128)
	{
		fib(25 + (i % 7));
		ticks = get_ticks(&t);
		c1 = temp[i % 16];
		temp[i % 16] = temp[ticks % 16];
		temp[ticks % 16] = c1;
	}
	return (temp);
}
