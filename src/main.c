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
#define TEXSIZE 64

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
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,5,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,7,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,7,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,7,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,7,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int texture[8][TEXSIZE * TEXSIZE];
int colors[6] ={0, 0x7F0000, 0x7F00, 0x7F, 0x7F7F7F, 0x7F7F};
int shade[6]= {0, 0xFF0000,  0xFF00, 0xFF, 0xFFFFFF, 0xFFFF};
// void			hs_clock_darwin_gettime(struct timespec *ts)
// {
// 	clock_serv_t		cclock;
// 	mach_timespec_t		mts;

// 	host_get_clock_service(mach_host_self(), CLOCK_REALTIME, &cclock);
// 	clock_get_time(cclock, &mts);
// 	mach_port_deallocate(mach_task_self(), cclock);
// 	ts->tv_sec = mts.tv_sec;
// 	ts->tv_nsec = mts.tv_nsec;
// }

// /*
// ** hack to count the time passed in seconds
// */
// static void		view_check_moment(t_env *v)
// {
// 	int				moment;
   
// 	moment	= (int)(v->cur_time / 100000000);
// 	if (!v->past && moment == 9)
// 	{
// 		v->cur_sec++;
// 		v->past = 1;
// 	}
// 	if (v->past && moment == 0)
// 		v->past = 0;
// }

// /*
// ** set the frame time and the move and rot speed using it
// */
// static void		calc_view_fps(t_env *v)
// {
// 	v->frame_time = (double)(v->cur_time - v->old_time) / 1000000000.0;
// 	if (v->frame_time > 0)
// 	{
// 		v->move_speed = (v->frame_time * 3.7);
// 		v->rot_speed = ((double)M_PI * v->frame_time / 1.25);
// 	}
// }

// void	update_time(t_env *v)
// {
// 	struct timespec	ts;
// 	view_check_moment(v);	
// 	hs_clock_darwin_gettime(&ts);
// 	v->old_time = v->cur_time;
// 	v->cur_time = ts.tv_nsec;
// 	printf("%f\n", v->cur_time );
// 	calc_view_fps(v);	
// }
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
	e->rot_speed = 0.016666 * 1.25;
	e->move_speed = 0.016666 * 3 ;
	e->past = 0;
	e->fps = 0.0f;
	e->cur_sec = 0;
	e->old_time = 0;
	int x = -1;
	int y;
	while (++x < TEXSIZE)
	{
		y = -1;
		while (++y < TEXSIZE)
		{
			int xorcolor = (x * 256 / TEXSIZE) ^ (y * 256 / TEXSIZE);
			int ycolor = y * 256 / TEXSIZE;
			int xycolor = y * 128 / TEXSIZE + x * 128 / TEXSIZE;
			texture[0][TEXSIZE * y + x] = 65536 * 254 * (x != y && x != TEXSIZE - y); //flat red texture with black cross
			texture[1][TEXSIZE * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
			texture[2][TEXSIZE * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
			texture[3][TEXSIZE * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
			texture[4][TEXSIZE * y + x] = 256 * xorcolor; //xor green
			texture[5][TEXSIZE * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
			texture[6][TEXSIZE * y + x] = 65536 * ycolor; //red gradient
			texture[7][TEXSIZE * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
		}
	}
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
	int		line_height;
	unsigned int		color;

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
	map.line_height = (int)(HEIGHT / map.perp_wall_dist);
	map.draw_start = -map.line_height / 2 + HEIGHT / 2;
	if(map.draw_start < 0)
		map.draw_start = 0;
	map.draw_end = map.line_height / 2 + HEIGHT / 2;
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
	static clock_t start = 0, end = 0;

	static int past = 1;
	static int frames = 0;
	// static double start = 0;
	static double passed = 0;
	static int first = 1;
	double fps = 0.0f;
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
		int tex_num = worldMap[map.mapX][map.mapY] - 1;

		double wallx;
		if (map.side == 0)
			wallx = e->posY + map.perp_wall_dist * map.ray_dir_y;
		else
			wallx = e->posX + map.perp_wall_dist * map.ray_dir_x;
		wallx -= floor((wallx));
		int tex_x = (int)(wallx * (double)(TEXSIZE));
		if (map.side == 0 && map.ray_dir_x > 0)
			tex_x = TEXSIZE - tex_x - 1;
		if (map.side == 0 && map.ray_dir_y < 0)
			tex_x = TEXSIZE - tex_x - 1;
		int y = map.draw_start - 1;
		while (++y < map.draw_end)
		{
			int d = y * 256 - HEIGHT * 128 + map.line_height * 128;
			int tex_y = ((d * TEXSIZE) / map.line_height) / 256;
			map.color = texture[tex_num][TEXSIZE * tex_y + tex_x];
			if (map.side == 1)
				map.color = (map.color >> 1) & 8355711;
			buffer[y][x] = map.color;
		}
		int i;
		int j;

		j = -1;
		while (++j < HEIGHT)
		{	
			put_pixel_img(e, x, j, buffer[j][x]);		// buffer[j][i] = 0;	
		}

		// draw_buffer(e, buffer);
		// f (map.side == 1)
		// 	map.color = colors[worldMap[map.mapX][map.mapY]];
		// else 
		// 	map.color = shade[worldMap[map.mapX][map.mapY]];
		// verLine(e, x, map.draw_start, map.draw_end, map.color);
		// double frameTime = 0.016667;//= (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
		
	}
	int i = -1;
	while (++i < HEIGHT)
	{
		int j = -1;
		while (++j < WIDTH)
		{
			buffer[i][j] = 0;
		}
	}
	start = end;
	end = clock();
	e->fps = (double)(end - start) / CLOCKS_PER_SEC;
	printf("frametime = %f\n start %lu  end %lu", e->fps, start, end );
	// if (first)
	// {
	// 	frames = 0;
	// 	start = passed;
	// 	first = 0;
	// }
	// if ()
	// update_time(e);
	// new = clock();
	// fps = (double)(new - old)/1000 ;
	// printf("new = %lu old = %lu fps = %f\n", new, old, fps);
	
	// else
	// {
	// 	printf("In else\n");
	// 	e->move_speed = 0.01666  * 5.0; //the constant value is in squares/second
	// 	e->rot_speed = 0.01666 * (double)M_PI * 1.5; //the constant value is in radians/second
	// }
	
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
	// if (!first)
	// {
	// 	e->fps = (double)(end - start) * 1000 / CLOCKS_PER_SEC;
	// }
	
	if (e->fps >= 1 / 60.0f)
	{
		e->move_speed = e->fps  * 15.0; //the constant value is in squares/second
		e->rot_speed = (double)M_PI * e->fps / 1.25; //the constant value is in radians/second
	}
	if (e->flags & SIGN)
	{
		if (e->flags & TRAN_V)
		{
			//both camera direction and camera plane must be rotated
			double oldDirX = e->dirX;
			double oldDirY = e->dirY;
			e->dirX = oldDirX * cos(e->rot_speed) - oldDirY * sin(e->rot_speed);
			e->dirY = oldDirX * sin(e->rot_speed) + oldDirY * cos(e->rot_speed);
			double oldPlaneX = e->planeX;
			double oldPlaneY = e->planeY;
			e->planeX = oldPlaneX * cos(e->rot_speed) - oldPlaneY * sin(e->rot_speed);
			e->planeY = oldPlaneX * sin(e->rot_speed) + oldPlaneY * cos(e->rot_speed);
		}
		else if (e->flags & TRAN_H)
		{
			if(worldMap[(int)(e->posX + e->dirX * e->move_speed)][(int)(e->posY)] == 0) e->posX += e->dirX * e->move_speed;
			if(worldMap[(int)(e->posX)][(int)(e->posY + e->dirY * e->move_speed)] == 0) e->posY += e->dirY * e->move_speed;
		}
	}
	else if (e->flags & TRAN_V)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = e->dirX;
		double oldDirY = e->dirY;
		e->dirX = oldDirX * cos(-e->rot_speed) - oldDirY * sin(-e->rot_speed);
		e->dirY = oldDirX * sin(-e->rot_speed) + oldDirY * cos(-e->rot_speed);
		double oldPlaneX = e->planeX;
		double oldPlaneY = e->planeY;
		e->planeX = oldPlaneX * cos(-e->rot_speed) - oldPlaneY * sin(-e->rot_speed);
		e->planeY = oldPlaneX * sin(-e->rot_speed) + oldPlaneY * cos(-e->rot_speed);
	}
	else if (e->flags & TRAN_H)
	{
		if(worldMap[(int)(e->posX - e->dirX * e->move_speed)][(int)(e->posY)] == 0) e->posX -= e->dirX * e->move_speed;
		if(worldMap[(int)(e->posX)][(int)(e->posY - e->dirY * e->move_speed)] == 0) e->posY -= e->dirY * e->move_speed;
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
	// ft_printf("keycode = %d", keycode);
	if (keycode == 124)
	{
		e->flags |= TRAN_V;
		//both camera direction and camera plane must be rotated
		// double oldDirX = e->dirX;
		// double oldDirY = e->dirY;
		// e->dirX = oldDirX * cos(-e->rot_speed) - oldDirY * sin(-e->rot_speed);
		// e->dirY = oldDirX * sin(-e->rot_speed) + oldDirY * cos(-e->rot_speed);
		// double oldPlaneX = e->planeX;
		// double oldPlaneY = e->planeY;
		// e->planeX = oldPlaneX * cos(-e->rot_speed) - oldPlaneY * sin(-e->rot_speed);
		// e->planeY = oldPlaneX * sin(-e->rot_speed) + oldPlaneY * cos(-e->rot_speed);
		// redraw_game(e);
	}
	else if (keycode == 123)
	{
		e->flags |= TRAN_V | SIGN;
		//both camera direction and camera plane must be rotated
		// double oldDirX = e->dirX;
		// double oldDirY = e->dirY;
		// e->dirX = oldDirX * cos(e->rot_speed) - oldDirY * sin(e->rot_speed);
		// e->dirY = oldDirX * sin(e->rot_speed) + oldDirY * cos(e->rot_speed);
		// double oldPlaneX = e->planeX;
		// double oldPlaneY = e->planeY;
		// e->planeX = oldPlaneX * cos(e->rot_speed) - oldPlaneY * sin(e->rot_speed);
		// e->planeY = oldPlaneX * sin(e->rot_speed) + oldPlaneY * cos(e->rot_speed);
		// redraw_game(e);
	}
	else if (keycode == 126)
	{
		e->flags |= TRAN_H | SIGN;
		// if(worldMap[(int)(e->posX + e->dirX * e->move_speed)][(int)(e->posY)] == 0) e->posX += e->dirX * e->move_speed;
		// if(worldMap[(int)(e->posX)][(int)(e->posY + e->dirY * e->move_speed)] == 0) e->posY += e->dirY * e->move_speed;
		// redraw_game(e);
	}
	else if (keycode == 125)
	{
		e->flags |= TRAN_H;
		// if(worldMap[(int)(e->posX - e->dirX * e->move_speed)][(int)(e->posY)] == 0) e->posX -= e->dirX * e->move_speed;
		// if(worldMap[(int)(e->posX)][(int)(e->posY - e->dirY * e->move_speed)] == 0) e->posY -= e->dirY * e->move_speed;
		// redraw_game(e);
	}
	return (0);
}
