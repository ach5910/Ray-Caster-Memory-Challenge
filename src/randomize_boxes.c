/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomize_boxes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 08:14:31 by                   #+#    #+#             */
/*   Updated: 2017/05/13 08:14:44 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <unistd.h>
#include <stdlib.h>

int fib(int i)
{
    return i < 2 ? 1 : fib(i-1) + fib(i-2);
}

int		*randomize_boxes(void)
{
	int *temp;
	int i;
	int c1;
	t_timer t;
	size_t ticks;

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
