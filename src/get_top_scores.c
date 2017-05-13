/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_top_scores.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ach5910@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 20:07:38 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/12 20:07:45 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	get_top_scores(t_env *e)
{
	int		i;
	int		fd;

	i = -1;
	fd = open("top_scores.txt", O_RDONLY);
	e->top_scores = (char**)malloc(sizeof(char*) * 10);
	while (++i < 10 )
		get_next_line(fd, &e->top_scores[i]);
	mlx_string_put(e->mlx, e->win, 315, 350, 16777215, "---TOP SCORES---");
	i = -1;
	while (++i < 10)
		mlx_string_put(e->mlx, e->win, 340, i * 15 + 370, 16777215, e->top_scores[i]);
	close(fd);
}
