/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 08:29:09 by ahunt             #+#    #+#             */
/*   Updated: 2017/01/16 08:29:12 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
int colors[6] ={0, 0x7F0000, 0x7F00, 0x7F, 0x7F7F7F, 0x7F7F};
int shade[6]= {0, 0xFF0000,  0xFF00, 0xFF, 0xFFFFFF, 0xFFFF};

int	main(void)
{
	t_env *e;

	e = init_environment();
	e->posX = 22;
	e->posY = 20;  //x and y start position
	e->dirX = -1;
	e->dirY = 0; //initial direction vector
	e->planeX = 0;
	e->planeY = 0.66;
	redraw_game(e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_hook(e->win, 2, 0, my_key_pressed, e);
	mlx_loop_hook(e->mlx, my_loop_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
typedef struct s_map
{
	double	cameraX;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double 	delta_y;
	double 	delta_x;
	double	perp_wall_dist;
	int		draw_start;
	int		draw_end;
	int		mapX;
	int		mapY;
	int		step_x;
	int		step_y;
	int		side;
	int		hit;
	int		color;

}				t_map;

double delta_dist_y(double ray_dir_y, double ray_dir_x)
{
	return (sqrt(1 + (ray_dir_x * ray_dir_x) / (ray_dir_y * ray_dir_y)));
}
double delta_dist_x(double ray_dir_y, double ray_dir_x)
{
	return (sqrt(1 + (ray_dir_y * ray_dir_y) / (ray_dir_x * ray_dir_x)));
}
t_map init_map(t_env *e, int x)
{
	t_map	map;

	map.cameraX = 2 * x / (double)WIDTH - 1; //x-coordinate in camera space
	map.ray_dir_x = e->dirX + e->planeX * map.cameraX;
	map.ray_dir_y = e->dirY + e->planeY * map.cameraX;
	map.mapX = (int)e->posX;
	map.mapY = (int)e->posY;
	map.delta_y = delta_dist_y(map.ray_dir_y, map.ray_dir_x);
	map.delta_x = delta_dist_x(map.ray_dir_y, map.ray_dir_x);
	map.hit = 0; //was there a wall hit?
	map.color = 0;
	return (map);
}

t_map check_if_hit(t_map map)
{
	//jump to next map square, OR in x-direction, OR in y-direction
	if (map.side_dist_x < map.side_dist_y)
	{
		map.side_dist_x += map.delta_x;
		map.mapX += map.step_x;
		map.side = 0;
	}
	else
	{
		map.side_dist_y += map.delta_y;
		map.mapY += map.step_y;
		map.side = 1;
	}
	//Check if ray has hit a wall
	if (worldMap[map.mapX][map.mapY] > 0) map.hit = 1;
	return (map);
}

t_map determine_line_size(t_map map)
{
	int line_height;

	line_height = (int)(HEIGHT / map.perp_wall_dist);
	map.draw_start = -line_height / 2 + HEIGHT / 2;
	if(map.draw_start < 0)
		map.draw_start = 0;
	map.draw_end = line_height / 2 + HEIGHT / 2;
	if(map.draw_end >= HEIGHT)
		map.draw_end = HEIGHT - 1;
	return (map);
}

double determine_wall_distance(t_env *e, t_map map)
{
	if (map.side == 0)
		return ((map.mapX - e->posX + (1 - map.step_x) / 2) / map.ray_dir_x);
	else
		return ((map.mapY - e->posY + (1 - map.step_y) / 2) / map.ray_dir_y);
}
void draw_image(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img->i_ptr, 0, 0);
	mlx_destroy_image(e->mlx, e->img->i_ptr);
	e->img->i_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
}

t_map calc_distances(t_env *e, t_map map)
{
	map.step_x = 1;
	map.side_dist_x = (map.mapX + 1.0 - e->posX) * map.delta_x;
	if (map.ray_dir_x < 0)
	{
		map.step_x = -1;
		map.side_dist_x = (e->posX - map.mapX) * map.delta_x;
	}
	map.step_y = 1;
	map.side_dist_y = (map.mapY + 1.0 - e->posY) * map.delta_y;
	if (map.ray_dir_y < 0)
	{
		map.step_y = -1;
		map.side_dist_y = (e->posY - map.mapY) * map.delta_y;
	}
	return (map);
}
// int tile = worldMap[map.mapX][map.mapY];
		// if (tile == 6)
		// 	tile = past
		// past = ((past + 1) % 6);
int redraw_game(t_env *e)
{
	static int past = 1;
	t_map map;
	int x;

	x = -1;
	while (++x < WIDTH)
	{
		map = init_map(e, x);
		map = calc_distances(e, map);
		while (map.hit == 0)
			map = check_if_hit(map);
		map.perp_wall_dist = determine_wall_distance(e, map);
		map = determine_line_size(map);
		if (map.side == 1)
			map.color = colors[worldMap[map.mapX][map.mapY]];
		else 
			map.color = shade[worldMap[map.mapX][map.mapY]];
		verLine(e, x, map.draw_start, map.draw_end, map.color);
		// double frameTime = 0.016667;//= (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
		e->moveSpeed = 0.016667 * 16.0; //the constant value is in squares/second
		e->rotSpeed = 0.016667 * 8.0; //the constant value is in radians/second
	}
	draw_image(e);
	return (0);
}

int expose_hook(t_env *e)
{
	redraw_game(e);
	return (0);
}

int my_loop_hook(t_env *e)
{
	if (e->flags & SIGN)
	{
		if (e->flags & TRAN_V)
		{
			//both camera direction and camera plane must be rotated
			double oldDirX = e->dirX;
			double oldDirY = e->dirY;
			e->dirX = oldDirX * cos(e->rotSpeed) - oldDirY * sin(e->rotSpeed);
			e->dirY = oldDirX * sin(e->rotSpeed) + oldDirY * cos(e->rotSpeed);
			double oldPlaneX = e->planeX;
			double oldPlaneY = e->planeY;
			e->planeX = oldPlaneX * cos(e->rotSpeed) - oldPlaneY * sin(e->rotSpeed);
			e->planeY = oldPlaneX * sin(e->rotSpeed) + oldPlaneY * cos(e->rotSpeed);
		}
		else if (e->flags & TRAN_H)
		{
			if(worldMap[(int)(e->posX + e->dirX * e->moveSpeed)][(int)(e->posY)] == 0) e->posX += e->dirX * e->moveSpeed;
			if(worldMap[(int)(e->posX)][(int)(e->posY + e->dirY * e->moveSpeed)] == 0) e->posY += e->dirY * e->moveSpeed;
		}
	}
	else if (e->flags & TRAN_V)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = e->dirX;
		double oldDirY = e->dirY;
		e->dirX = oldDirX * cos(-e->rotSpeed) - oldDirY * sin(-e->rotSpeed);
		e->dirY = oldDirX * sin(-e->rotSpeed) + oldDirY * cos(-e->rotSpeed);
		double oldPlaneX = e->planeX;
		double oldPlaneY = e->planeY;
		e->planeX = oldPlaneX * cos(-e->rotSpeed) - oldPlaneY * sin(-e->rotSpeed);
		e->planeY = oldPlaneX * sin(-e->rotSpeed) + oldPlaneY * cos(-e->rotSpeed);
	}
	else if (e->flags & TRAN_H)
	{
		if(worldMap[(int)(e->posX - e->dirX * e->moveSpeed)][(int)(e->posY)] == 0) e->posX -= e->dirX * e->moveSpeed;
		if(worldMap[(int)(e->posX)][(int)(e->posY - e->dirY * e->moveSpeed)] == 0) e->posY -= e->dirY * e->moveSpeed;
	}
	if (e->flags)
	{
		e->flags = 0;
		redraw_game(e);
	}
	return (0);
}
int my_key_pressed(int keycode, t_env *e)
{
	if (keycode == 124)
	{
		e->flags |= TRAN_V;
		//both camera direction and camera plane must be rotated
		// double oldDirX = e->dirX;
		// double oldDirY = e->dirY;
		// e->dirX = oldDirX * cos(-e->rotSpeed) - oldDirY * sin(-e->rotSpeed);
		// e->dirY = oldDirX * sin(-e->rotSpeed) + oldDirY * cos(-e->rotSpeed);
		// double oldPlaneX = e->planeX;
		// double oldPlaneY = e->planeY;
		// e->planeX = oldPlaneX * cos(-e->rotSpeed) - oldPlaneY * sin(-e->rotSpeed);
		// e->planeY = oldPlaneX * sin(-e->rotSpeed) + oldPlaneY * cos(-e->rotSpeed);
		// redraw_game(e);
	}
	else if (keycode == 123)
	{
		e->flags |= TRAN_V | SIGN;
		//both camera direction and camera plane must be rotated
		// double oldDirX = e->dirX;
		// double oldDirY = e->dirY;
		// e->dirX = oldDirX * cos(e->rotSpeed) - oldDirY * sin(e->rotSpeed);
		// e->dirY = oldDirX * sin(e->rotSpeed) + oldDirY * cos(e->rotSpeed);
		// double oldPlaneX = e->planeX;
		// double oldPlaneY = e->planeY;
		// e->planeX = oldPlaneX * cos(e->rotSpeed) - oldPlaneY * sin(e->rotSpeed);
		// e->planeY = oldPlaneX * sin(e->rotSpeed) + oldPlaneY * cos(e->rotSpeed);
		// redraw_game(e);
	}
	else if (keycode == 126)
	{
		e->flags |= TRAN_H | SIGN;
		// if(worldMap[(int)(e->posX + e->dirX * e->moveSpeed)][(int)(e->posY)] == 0) e->posX += e->dirX * e->moveSpeed;
		// if(worldMap[(int)(e->posX)][(int)(e->posY + e->dirY * e->moveSpeed)] == 0) e->posY += e->dirY * e->moveSpeed;
		// redraw_game(e);
	}
	else if (keycode == 125)
	{
		e->flags |= TRAN_H;
		// if(worldMap[(int)(e->posX - e->dirX * e->moveSpeed)][(int)(e->posY)] == 0) e->posX -= e->dirX * e->moveSpeed;
		// if(worldMap[(int)(e->posX)][(int)(e->posY - e->dirY * e->moveSpeed)] == 0) e->posY -= e->dirY * e->moveSpeed;
		// redraw_game(e);
	}
	return (0);
}
