/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fre.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ach5910@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 18:47:41 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/12 18:47:55 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	free_world_map(int **wm)
{
	int i;

	i = -1;
	while (++i < MAPWIDTH)
		ft_memdel((void **)&wm[i]);
	ft_memdel((void **)wm);
}

void	free_textures(int **t)
{
	int i;

	i = -1;
	while (++i < 21)
		ft_memdel((void **)&t[i]);
	ft_memdel((void **)t);
}

void	free_image(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img->i_ptr);
	ft_memdel((void**)&e->img);
	ft_memdel((void**)&e->win);
	ft_memdel((void**)&e->mlx);
}

void	free_scores(char **scores)
{
	int i;

	i = -1;
	while (++i < 10)
		ft_memdel((void **)&scores[i]);
	ft_memdel((void **)&scores);
}

void	free_environment(t_env *e)
{
	free_world_map(e->world_map);
	ft_memdel((void **)&e->values);
	free_textures(e->texture);
	ft_memdel((void **)&e->player);
}
