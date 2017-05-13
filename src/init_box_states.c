/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_box_states.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ahunt@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:37:50 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/13 14:37:51 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	*init_box_states(void)
{
	int i;
	int	*dest;

	dest = (int*)malloc(sizeof(int) * 16);
	i = -1;
	while (++i < 16)
		dest[i] = 1;
	return (dest);
}
