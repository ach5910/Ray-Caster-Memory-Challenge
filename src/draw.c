/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 09:32:33 by ahunt             #+#    #+#             */
/*   Updated: 2017/01/16 09:32:44 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	put_pixel_img_hud(t_env *e, int i, int j, int color)
{
	int x;
	int y;

	y = -1;
	while (++y < 5)
	{
		x = -1;
		while (++x < 5)
			put_pixel_img(e, i + x, j + y, color);
	}
}

void	put_pixel_img_per(t_env *e, int i, int j, int color)
{
	int x;
	int y;

	y = -1;
	while (++y < 3)
	{
		x = -1;
		while (++x < 3)
			put_pixel_img(e, i + x, j + y, color);
	}
}

void	refresh_img(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img->i_ptr, 0, 0);
	update_timer(e);
	mlx_destroy_image(e->mlx, e->img->i_ptr);
	e->img->i_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
}

void	draw_map(t_env *e, t_map map)
{
	int i;
	int j;
	int col;

	j = -1;
	while (++j < MAPWIDTH)
	{
		i = -1;
		while (++i < MAPHEIGHT)
		{
			col = e->world_map[i][j];
			if (col > 4 && e->values[col - 5] == -1)
				col = e->texture[col][TEXSIZE];
			else
				col = 0XFFFFFF;
			if (e->world_map[i][j] != 0)
				put_pixel_img_hud(e, j * 5, i * 5, col);
			else
				put_pixel_img_hud(e, j * 5, i * 5, 0);
		}
	}
	put_pixel_img_per(e, (int)(e->pos_y + 0.5) * 5,
		(int)(e->pos_x + 0.5) * 5, 0xFE00FF);
	refresh_img(e);
}

void	put_pixel_img(t_env *e, int i, int j, int color)
{
	int	p;

	p = (i * 4) + (j * e->img->size_line);
	e->img->data[p] = color & 0xFF;
	e->img->data[++p] = (color >> 8) & 0xFF;
	e->img->data[++p] = (color >> 16) & 0xFF;
}
