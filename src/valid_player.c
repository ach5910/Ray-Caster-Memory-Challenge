/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ahunt@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:40:04 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/13 14:40:06 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		valid_player(char *player)
{
	int len;
	int i;

	len = ft_strlen(player);
	if (len < 3 || len > 10)
		return (0);
	i = -1;
	while (player[++i])
	{
		if (!ft_isalpha(player[i]))
			return (0);
	}
	return (1);
}
