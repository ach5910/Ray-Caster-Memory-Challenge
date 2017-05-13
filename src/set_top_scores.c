/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_top_scores.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ahunt@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:39:24 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/13 14:39:26 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	display_top_scores(t_env *e, char *score)
{
	int		i;
	int		cnt;
	char	*temp;

	i = 0;
	cnt = -1;
	temp = ft_strjoin(score, " - ");
	temp = ft_strapp(temp, e->player);
	temp = ft_strpre("->", temp);
	mlx_string_put(e->mlx, e->win, 315, 350, 16777215, "---TOP SCORES---");
	while (++cnt < 10)
	{
		if (atoi(score) > atoi(e->top_scores[i]) && cnt == i)
			mlx_string_put(e->mlx, e->win, 320, cnt * 15 + 370,
				16777215, temp);
		else
			mlx_string_put(e->mlx, e->win, 340, cnt * 15 + 370,
				16777215, e->top_scores[i]);
	}
	ft_memdel((void **)&temp);
}

void	set_top_scores(t_env *e, char *score)
{
	int		i;
	int		cnt;
	int		fd;
	char	*temp;

	display_top_scores(e, score);
	fd = open("top_scores.txt", O_WRONLY);
	i = 0;
	cnt = -1;
	temp = ft_strjoin(score, " - ");
	temp = ft_strapp(temp, e->player);
	while (++cnt < 10)
	{
		if (atoi(score) > atoi(e->top_scores[i]) && cnt == i)
			ft_putendl_fd(temp, fd);
		else
			ft_putendl_fd(e->top_scores[i++], fd);
	}
	close(fd);
	ft_memdel((void **)&temp);
}
