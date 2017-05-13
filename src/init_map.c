#include "wolf.h"

t_map	init_map(t_env *e, int x)
{
	t_map	map;

	map.cameraX = 2 * x / (double)WIDTH  - 1; //x-coordinate in camera space
	map.ray_dir_x = e->dirX + e->planeX * map.cameraX;
	map.ray_dir_y = e->dirY + e->planeY * map.cameraX;
	map.rpx = e->posX;
	map.rpy = e->posY;
	map.mapX = (int)map.rpx;
	map.mapY = (int)map.rpy;
	map.delta_y = delta_dist_y(map.ray_dir_y, map.ray_dir_x);
	map.delta_x = delta_dist_x(map.ray_dir_y, map.ray_dir_x);
	map.hit = 0; //was there a wall hit?
	map.color = 0;
	return (map);
}
