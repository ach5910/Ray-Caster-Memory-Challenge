/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_top_scores.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 04:51:33 by                   #+#    #+#             */
/*   Updated: 2017/05/13 04:51:44 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	set_top_scores(t_env *e, char *score)
{
	int i;
	int cnt;
	int fd;
	char *temp;

	fd = open("top_scores.txt", O_WRONLY);
	i = 0;
	cnt = -1;
	temp = ft_strjoin(score, " - ");
	temp = ft_strapp(temp, e->player);
	mlx_string_put(e->mlx, e->win, 315, 350, 16777215, "---TOP SCORES---");
	while (++cnt < 10)
	{
		if (atoi(score) > atoi(e->top_scores[i]) && cnt == i)
		{
			ft_putendl_fd(temp, fd);
			temp = ft_strpre("->", temp);
			mlx_string_put(e->mlx, e->win, 320, cnt * 15 + 370, 16777215, temp);
		}
		else
		{
			mlx_string_put(e->mlx, e->win, 340, cnt * 15 + 370, 16777215, e->top_scores[i]);
			ft_putendl_fd(e->top_scores[i++], fd);
		}
	}
	close(fd);
	ft_memdel((void **)&temp);
}
