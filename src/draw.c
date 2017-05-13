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

void verLine(t_env *e, int x, int drawStart, int drawEnd, int color)
{
	t_vec2	*p1;
	t_vec2	*p2;

	p1 = (t_vec2*)malloc(sizeof(t_vec2));
	p2 = (t_vec2*)malloc(sizeof(t_vec2));
	p1->x = x;
	p1->y = drawStart;
	p2->x = x;
	p2->y = drawEnd;
	draw_lines_y(e, p1, p2, color);
}

t_line	*get_line_params_y(t_env *e, t_vec2 *p1, t_vec2 *p2)
{
	t_line	*data;

	data = (t_line*)malloc(sizeof(t_line));
	data->dx = fabs(p1->x - p2->x);
	data->dy = fabs(p1->y - p2->y);
	data->p = (2 * data->dx) - data->dy;
	data->end = p2->y > p1->y ? p2 : p1;
	data->start = p2->y > p1->y ? p1 : p2;
	data->i = data->start->y;
	data->j = data->start->x;
	data->j_incr = data->end->x > data->start->x ? 1 : -1;
	return (data);
}

void	draw_lines_y(t_env *e, t_vec2 *p1, t_vec2 *p2, int color)
{
	t_line	*d;

	d = get_line_params_y(e, p1, p2);
	// mlx_pixel_put(e->mlx, e->win, d->j, d->i, color);
	put_pixel_img(e, d->j, d->i, color);
	while (d->i < d->end->y)
	{
		// ßmlx_pixel_put(e->mlx, e->win, d->j, d->i, color);
		put_pixel_img(e, d->j, d->i, color);
		if (d->p < 0)
			d->p += (2 * d->dx);
		else
		{
			d->p += (2 * d->dx) - (2 * d->dy);
			d->j += d->j_incr;
		}
		d->i++;
	}
	ft_memdel((void **)&d);

}
int ct;

void put_pixel_img_hud(t_env *e, int i, int j, int color, int n)
{
	int x;
	int y;

	y = -1;
	while (++y < n)
	{
		x = -1;
		while (++x < n)
			put_pixel_img(e, i + x, j + y, color);
	}
}

void draw_map(t_env *e, t_map map)
{
	int i;
	int j;
	int col;

	j = -1;
	while (++j < mapWidth)
	{
		i = -1;
		while (++i < mapHeight)
		{	
			col = e->world_map[i][j];
			if (col > 4 && e->values[col - 5] == -1)
				col = e->texture[col][TEXSIZE];
			else
				col = 0xFFFFFF;	
			if (e->world_map[i][j] != 0)
				put_pixel_img_hud(e,j * 5, i * 5, col, 5);
			else
				put_pixel_img_hud(e,j * 5, i * 5 , 0, 5);
		}
	}
	
	ct = 0;
	put_pixel_img_hud(e,  (int)(e->posY + 0.5) * 5,(int)(e->posX + 0.5) * 5,0xFE00FF, 3);
	mlx_put_image_to_window(e->mlx, e->win, e->img->i_ptr, 0, 0);
	update_timer(e);
	mlx_destroy_image(e->mlx, e->img->i_ptr);
	e->img->i_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
}

void draw_buffer(t_env *e, unsigned int buf[640][800])
{
	int i;
	int j;

	j = -1;
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			put_pixel_img(e, i, j, buf[j][i]);
		}
	}
}
void put_pixel_img_mini(t_env *e, int i, int j, int color, int n)
{
	if (n == 0)
		return ;
	printf("%d\n", ++ct);
	int	p;
	p = (i * 4) + (j * e->img->size_line);
	e->img->data[p] = color & 0xFF;
	e->img->data[++p] = (color >> 8) & 0xFF;
	e->img->data[++p] = (color >> 16) & 0xFF;
	put_pixel_img_mini(e, i + 1, j, color, n - 1);
	put_pixel_img_mini(e, i, j + 1, color, n - 1);
	put_pixel_img_mini(e, i + 1, j + 1, color, n - 1);
}
void put_pixel_img(t_env *e, int i, int j, int color)
{

	int	p;
	p = (i * 4) + (j * e->img->size_line);
	e->img->data[p] = color & 0xFF;
	e->img->data[++p] = (color >> 8) & 0xFF;
	e->img->data[++p] = (color >> 16) & 0xFF;
}
