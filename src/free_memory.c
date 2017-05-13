#include "wolf.h"

void free_world_map(int **wm)
{
	int i;

	i = -1;
	while (++i < mapWidth)
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

void	free_buffer(unsigned int **b)
{
	int i;

	i = -1;
	while (++i < HEIGHT + 1)
		ft_memdel((void **)&b[i]);
	ft_memdel((void **)b);
}

void free_image(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img->i_ptr);
	ft_memdel((void**)&e->img);
	ft_memdel((void**)&e->win);
	ft_memdel((void**)&e->mlx);
}

void free_environment(t_env *e)
{
	free_world_map(e->world_map);
	ft_memdel((void **)&e->values);
	free_textures(e->texture);
	free_buffer(e->buffer);

}