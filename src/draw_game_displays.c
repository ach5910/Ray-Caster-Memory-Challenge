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

void	calculate_final_score(t_env *e, t_scores *s)
{
	int	blk_b;
	int	tm_b;
	int	tot_sc;

	blk_b = (16 - e->blocks) * e->strk_mult * 100;
	tm_b = e->time_left * 100;
	tot_sc = blk_b + tm_b;
	s->block_bonus = ft_itoa_base((size_t)blk_b, 10, 1);
	s->time_bonus = ft_itoa_base((size_t)tm_b, 10, 1);
	s->total_score = ft_itoa_base((size_t)tot_sc, 10, 1);
}

void	draw_game_over(t_env *e)
{
	t_scores sc;

	e->game_state = GAMEOVER;
	draw_panel(e);
	calculate_final_score(e, &sc);
	mlx_string_put(e->mlx, e->win, 350, 160, 16777215, "GAME OVER");
	mlx_string_put(e->mlx, e->win, 300, 200, 16777215, "Block Bonus : ");
	mlx_string_put(e->mlx, e->win, 450, 200, 16777215, sc.block_bonus);
	mlx_string_put(e->mlx, e->win, 300, 220, 16777215, "Time Bonus  : ");
	mlx_string_put(e->mlx, e->win, 450, 220, 16777215, sc.time_bonus);
	mlx_string_put(e->mlx, e->win, 290, 230, 16777215,
		"________________________");
	mlx_string_put(e->mlx, e->win, 300, 250, 16777215, "Final Score : ");
	mlx_string_put(e->mlx, e->win, 450, 250, 16777215, sc.total_score);
	mlx_string_put(e->mlx, e->win, 300, 300, 16777215,
		"**PRESS ESC TO CLOSE**");
	set_top_scores(e, sc.total_score);
	ft_memdel((void **)&sc.total_score);
	ft_memdel((void **)&sc.block_bonus);
	ft_memdel((void **)&sc.time_bonus);
}

void	draw_game_start(t_env *e)
{
	draw_panel(e);
	mlx_string_put(e->mlx, e->win, 290, 100, 16777215,
		"WOLF 3D - MEMORY BLOCKS");
	mlx_string_put(e->mlx, e->win, 290, 110, 16777215,
		"_______________________");
	mlx_string_put(e->mlx, e->win, 100, 190, 16777215,
		"\"Try to find all pairs of matchin blocks before time runs out\"");
	mlx_string_put(e->mlx, e->win, 100, 240, 16777215,
		"Use Arrows to rotate player and move forwards and backwards");
	mlx_string_put(e->mlx, e->win, 100, 255, 16777215,
		"Press Space Bar while touching block to reveal it's color");
	mlx_string_put(e->mlx, e->win, 100, 270, 16777215,
		"Once a pair is found the blocks are removed and time is added");
	mlx_string_put(e->mlx, e->win, 280, 300, 16777215,
		"**PRESS SPACE BAR TO START**");
	get_top_scores(e);
}
