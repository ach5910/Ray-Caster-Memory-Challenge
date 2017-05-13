/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game_over.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ach5910@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:05:12 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/12 19:05:28 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_panel(t_env *e)
{
	int i;
	int j;

	i = -1;
	while (++i < 800)
	{
		j = 99;
		while (++j < 550)
			mlx_pixel_put(e->mlx, e->win, i, j, 0);
	}
}


void	set_top_scores(t_env *e, char *score)
{
	int i;
	int cnt;
	int fd;

	fd = open("top_scores.txt", O_WRONLY);
	i = 0;
	cnt = 0;
	while (cnt < 10)
	{
		if (atoi(score) > atoi(e->top_scores[i]) && cnt == i)
		{
			ft_putstr_fd(score, fd);
			ft_putstr_fd(" - ", fd);
			ft_putendl_fd(e->player, fd);
		}
		else
		{
			ft_putendl_fd(e->top_scores[i], fd);
			i++;
		}
		cnt++;
	}
	close(fd);
}

void	free_scores(t_env *e)
{
	int i;

	i = -1;
	while (++i < 10)
		ft_memdel((void **)&e->top_scores[i]);
	ft_memdel((void **)&e->top_scores);
}

void	draw_game_over(t_env *e)
{
	size_t	block_bonus;
	size_t 	time_bonus;
	char	*total_score;

	draw_panel(e);
	block_bonus = (size_t)(16 - e->blocks) * 100;
	time_bonus = (size_t)e->time_left * 100;
	total_score = ft_itoa_base(block_bonus + time_bonus, 10, 1);
	mlx_string_put(e->mlx, e->win, 350, 160, 16777215, "GAME OVER");
	mlx_string_put(e->mlx, e->win, 300, 200, 16777215, "Block Bonus : ");
	mlx_string_put(e->mlx, e->win, 450, 200, 16777215, ft_itoa_base(block_bonus, 10, 1));
	mlx_string_put(e->mlx, e->win, 300, 220, 16777215, "Time Bonus  : ");
	mlx_string_put(e->mlx, e->win, 450, 220, 16777215, ft_itoa_base(time_bonus, 10, 1));
	mlx_string_put(e->mlx, e->win, 300, 240, 16777215, "Final Score : ");
	mlx_string_put(e->mlx, e->win, 450, 240, 16777215, total_score);
	mlx_string_put(e->mlx, e->win, 250, 330, 16777215, 
		"**PRESS SPACE BAR TO CONTINUE**");
	set_top_scores(e, total_score);
	// ft_memdel((void **)&total_score);
	// free_scores(e);
}

void	draw_game_start(t_env *e)
{

	printf("in game start\n");
	draw_panel(e);
	mlx_string_put(e->mlx, e->win, 290, 160, 16777215, "WOLF 3D - MEMORY BLOCKS");
	mlx_string_put(e->mlx, e->win, 100, 190, 16777215, 
		"\"Try to find all pairs of matchin blocks before time runs out\"");
	mlx_string_put(e->mlx, e->win, 250, 240, 16777215, 
		"Use Arrows to manuever around the map");
	mlx_string_put(e->mlx, e->win, 120, 255, 16777215, 
		"Press Space Bar while touching block to reveal it's color");
	mlx_string_put(e->mlx, e->win, 100, 270, 16777215, 
		"Once a pair is found the blocks are removed and time is added");
	mlx_string_put(e->mlx, e->win, 280, 300, 16777215, "**PRESS SPACE BAR TO START**");
	get_top_scores(e);
}