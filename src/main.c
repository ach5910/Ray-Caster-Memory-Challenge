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

// int get_array(int a, int b, int c, int d, int e)
// {
// static int worldMap[mapWidth][mapHeight]=
// {
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//   {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
//   {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
//   {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
//   {2,0,0,0,5,0,0,0,0,6,0,0,0,0,7,0,0,0,0,8,0,0,0,4},
//   {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
//   {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
//   {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
//   {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
//   {2,0,0,0,9,0,0,0,0,10,0,0,0,0,11,0,0,0,0,12,0,0,0,4},
//   {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
//   {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
//   {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
//   {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
//   {2,0,0,0,17,0,0,0,0,13,0,0,0,0,16,0,0,0,0,19,0,0,0,4},
//   {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
//   {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
//   {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
//   {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
//   {2,0,0,0,14,0,0,0,0,15,0,0,0,0,20,0,0,0,0,18,0,0,0,4},
//   {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
//   {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
//   {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
//   {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}
// };
// 	worldMap[c][d] = e;
// 	return (worldMap[a][b]);
// }

int **init_grid()
{
	int i;
	int j;
	int **dest;

	dest = (int**)malloc(sizeof(int*) * mapWidth);
	i = -1;
	while (++i < mapWidth)
	{
		dest[i] = (int*)malloc(sizeof(int) * mapHeight);
		j = -1;
		while (++j < mapHeight)
		{
			if (i == 0)
				dest[i][j] = 2;
			else if (i == 23)
				dest[i][j] = 4;
			else if (j == 0)
				dest[i][j] = 1;
			else if (j == 23)
				dest[i][j] = 4;
			else
				dest[i][j] = 0;
		}
	}
	dest[4][4] = 5;
	dest[4][9] = 9;
	dest[4][14] = 17;
	dest[4][19] = 14;
	dest[9][4] = 6;
	dest[9][9] = 10;
	dest[9][14] = 13;
	dest[9][19] = 15;
	dest[14][4] = 7;
	dest[14][9] = 11;
	dest[14][14] = 16;
	dest[14][19] = 20;
	dest[19][4] = 8;
	dest[19][9] = 12;
	dest[19][14] = 19;
	dest[19][19] = 18;
	return (dest);

}

// int e->texture[8][TEXSIZE * TEXSIZE];


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
int **malloc_texture()
{
	int i;
	int **temp;

	temp = (int**)malloc(sizeof(int*) * 21);
	i = -1;
	while (++i < 21)
		temp[i] = (int*)malloc(sizeof(int) * TEXSIZE * TEXSIZE);
	return (temp);
}

int **set_textures()
{
	int x;
	int y;
	int	**dest;

	dest = malloc_texture();
	x = -1;
	while (++x < TEXSIZE)
	{
		y = -1;
		while (++y < TEXSIZE)
		{
			int xorcolor = (x * 256 / TEXSIZE) ^ (y * 256 / TEXSIZE);
			int ycolor = y * 256 / TEXSIZE;
			int xycolor = y * 128 / TEXSIZE + x * 128 / TEXSIZE;
			dest[0][TEXSIZE * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //flat red e->texture with black cross
			dest[1][TEXSIZE * y + x] = 128 * xycolor + 65536 * xycolor; //sloped greyscale128 + 240 * 128 + 65536 * 128;
			dest[2][TEXSIZE * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //sloped yellow gradientxorcolor + 252 * xorcolor + 65536 * xorcolor; 
			dest[3][TEXSIZE * y + x] = xorcolor + 128 * xorcolor + 65536 * xorcolor; //xor greyscale254 * xycolor + 65536 * xycolor;
			dest[4][TEXSIZE * y + x] = 65534 * 256 * (x != y && x != TEXSIZE - y); //xor greenxycolor + 256 * xycolor + 65536 * xycolor;
			dest[5][TEXSIZE * y + x] = 0XFF1493;//0xFFFFFF;//65536 * 192 * (x % 16 && y % 16); //red bricks
			dest[6][TEXSIZE * y + x] = 0X8B4513;//254 * xycolor + 65536 * xycolor; //red gradient254 * xycolor + 65536 * xycolor;
			dest[7][TEXSIZE * y + x] = 0X9932CC;//256 * xorcolor; //flat grey e->texture
			dest[8][TEXSIZE * y + x] = 	0X006400;
			dest[9][TEXSIZE * y + x] = 0X00FFFF;
			dest[10][TEXSIZE * y + x] = 0X00008B;
			dest[11][TEXSIZE * y + x] = 0xDC143C;
			dest[12][TEXSIZE * y + x] = 0XADFF2F;
			dest[13][TEXSIZE * y + x] = 0XFF1493;//0xFFFFFF;//65536 * 192 * (x % 16 && y % 16); //red bricks
			dest[14][TEXSIZE * y + x] = 0X8B4513;//254 * xycolor + 65536 * xycolor; //red gradient254 * xycolor + 65536 * xycolor;
			dest[15][TEXSIZE * y + x] = 0X9932CC;//256 * xorcolor; //flat grey e->texture
			dest[16][TEXSIZE * y + x] = 0X006400;
			dest[17][TEXSIZE * y + x] = 0X00FFFF;
			dest[18][TEXSIZE * y + x] = 0X00008B;
			dest[19][TEXSIZE * y + x] = 0xDC143C;
			dest[20][TEXSIZE * y + x] = 0XADFF2F;
		}
	}
	return (dest);
}

unsigned int **malloc_buffer()
{
	int x;
	unsigned int **dest;

	x = -1;
	dest = (unsigned int**)malloc(sizeof(unsigned int*) * HEIGHT + 1);
	while (++x < HEIGHT)
	{
		dest[x] = (unsigned int*)malloc(sizeof(unsigned int) * WIDTH + 1);
	}
	return (dest);
}

int	*init_box_states(void)
{
	int i;
	int	*dest;

	dest = (int*)malloc(sizeof(int) * 16);
	i = -1;
	while (++i < 16)
		dest[i] = 1;
	return (dest);
}

t_env *init_parameters(t_env *e)
{
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
	e->last_color = 0;
	e->values = init_box_states();
	e->texture = set_textures();
	e->buffer = malloc_buffer();
	e->world_map = init_grid();
	return (e);
}
int	main(void)
{
	t_env *e;

	e = init_environment();
	e = init_parameters(e);
	redraw_game(e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_hook(e->win, 2, 0, my_key_pressed, e);
	mlx_loop_hook(e->mlx, my_loop_hook, e);
	mlx_loop(e->mlx);
	return (0);
}


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

t_map check_if_hit(t_map map, t_env *e)
{
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
	printf("%d  %d\n",map.mapX, map.mapY);
	if (e->world_map[map.mapX][map.mapY] > 0) 
		map.hit = 1;
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
		return ((map.mapX - map.rpx + (1 - map.step_x) / 2) / map.ray_dir_x);
	else
		return ((map.mapY - map.rpy + (1 - map.step_y) / 2) / map.ray_dir_y);
}

void fill_texture_buffer(t_map map,t_env *e, int x)
{
	int d;
	int y;

	y = -1;
	while (++y < map.draw_end)
	{
		d = y * 256 - HEIGHT * 128 + map.line_height * 128;
		map.tex_y = ((d * TEXSIZE) / map.line_height) / 256;
		if (map.tex_num < 5 || (e->last_color == map.tex_num  && e->last_color > 4 && e->values[e->last_color - 5] < 0))
		{
			map.color = e->texture[map.tex_num][TEXSIZE * map.tex_y + map.tex_x];
		}
		else
			map.color = 0xFFFFFF;
		if (map.side == 1)
			map.color = (map.color >> 1) & 8355711;
		e->buffer[y][x] = map.color;
	}
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

t_map floor_casting(t_map map)
{
	if (map.side == 0 * map.ray_dir_x > 0)
	{
		map.floor_x_wall = map.mapX;
		map.floor_y_wall = map.mapY + map.wallx;
	}
	else if (map.side == 0 * map.ray_dir_x < 0)
	{
		map.floor_x_wall = map.mapX + 1.0;
		map.floor_y_wall = map.mapY + map.wallx;
	}
	else if (map.side == 1 && map.ray_dir_y > 0)
	{
		map.floor_x_wall = map.mapX + map.wallx;
		map.floor_y_wall = map.mapY;
	}
	else
	{
		map.floor_x_wall = map.mapX + map.wallx;
		map.floor_y_wall = map.mapY + 1.0;
	}
	return (map);
}

void buffer_to_image(t_env *e, int x)
{
	int j;
	j = -1;
	while (++j < HEIGHT)
	{	
		if (x > 120 || j > 120)
			put_pixel_img(e, x, j, e->buffer[j][x]);		// buffer[j][i] = 0;	
	}
}

void clear_buffer(t_env *e)
{
	int i = -1;
	while (++i < HEIGHT)
	{
		int j = -1;
		while (++j < WIDTH)
			e->buffer[i][j] = 0;
	}
}

void draw_floor(t_map map,t_env *e, int x)
{
	int y;
	double cur_fl_x;
	double cur_fl_y;
	int fl_tx_x;
	int	fl_tx_y;

	y = map.draw_end;
	while (++y < HEIGHT)
	{
		map.cur_dist = HEIGHT / (2.0 * y - HEIGHT);
		map.weight = (map.cur_dist - map.dist_player) / (map.dist_wall - map.dist_player);
		cur_fl_x = map.weight * map.floor_x_wall + (1.0 - map.weight) * map.rpx;
		cur_fl_y = map.weight * map.floor_y_wall + (1.0 - map.weight) * map.rpy;
		fl_tx_x = (int)(cur_fl_x * TEXSIZE) % TEXSIZE;
		fl_tx_y = (int)(cur_fl_y * TEXSIZE) % TEXSIZE;
		e->buffer[y][x] = (e->texture[0][TEXSIZE * fl_tx_y + fl_tx_x] >> 1) & 8355711;
		e->buffer[(HEIGHT - y)][  x] = (e->texture[0][TEXSIZE * fl_tx_y + fl_tx_x]);
	}
}

t_map get_wallx(t_map map)
{
	if (map.side == 0)
		map.wallx = map.rpy + map.perp_wall_dist * map.ray_dir_y;
	else
		map.wallx = map.rpx + map.perp_wall_dist * map.ray_dir_x;
	map.wallx -= floor((map.wallx));
	return (map);
}

t_map get_texture_x(t_map map)
{
	map.tex_x = (int)(map.wallx * (double)(TEXSIZE));
	if (map.side == 0 && map.ray_dir_x > 0)
		map.tex_x = TEXSIZE - map.tex_x - 1;
	if (map.side == 1 && map.ray_dir_y < 0)
		map.tex_x = TEXSIZE - map.tex_x - 1;
	return (map);
}
void rotatate_view(t_env *e, double dir_x, double plane_x, int s)
{
	double oldDirY;
	double oldPlaneY;

	oldDirY = e->dirY;
	oldPlaneY = e->planeY;
	e->dirX = dir_x * cos(s * e->rot_speed) - oldDirY * sin(s * e->rot_speed);
	e->dirY = dir_x * sin(s * e->rot_speed) + oldDirY * cos(s * e->rot_speed);
	e->planeX = plane_x * cos(s * e->rot_speed)
		- oldPlaneY * sin(s * e->rot_speed);
	e->planeY = plane_x * sin(s * e->rot_speed)
		+ oldPlaneY * cos(s * e->rot_speed);
}

void move_player(t_env *e, int s)
{
	if(e->world_map[(int)(e->posX + s * e->dirX * e->move_speed)][(int)(e->posY)] == 0)
		e->posX = e->posX + s * e->dirX * e->move_speed;
	if(e->world_map[(int)(e->posX)][(int)(e->posY + s * e->dirY * e->move_speed)] == 0)
		e->posY = e->posY + s * e->dirY * e->move_speed;
}

int redraw_game(t_env *e)
{
	t_map map;
	int x;

	x = -1;
	while (++x < WIDTH)
	{
		map = init_map(e, x);
		printf("after init\n");
		map = calc_distances(e, map);
		printf("after calc\n");
		while (map.hit == 0)
			map = check_if_hit(map, e);
		printf("after if hit\n");
		map.perp_wall_dist = determine_wall_distance(e, map);
		printf("after determine_wall_distance\n");
		map = determine_line_size(map);
		printf("after determine_line_size\n");
		map.tex_num = e->world_map[map.mapX][map.mapY];
		if (e->values[map.tex_num - 5] == 0)
			e->world_map[map.mapX][map.mapY] = 0;
		map = get_wallx(map);
		map = get_texture_x(map);
		fill_texture_buffer(map, e, x);
		map = floor_casting(map);
		map.dist_wall = map.perp_wall_dist;
		map.dist_player = 0.0;
		if (map.draw_end < 0)
			map.draw_end = HEIGHT;
		draw_floor(map, e, x);
		buffer_to_image(e, x);
	}
	clear_buffer(e);
	draw_map(e, map);
	return (0);
}

int expose_hook(t_env *e)
{
	redraw_game(e);
	return (0);
}

int my_loop_hook(t_env *e)
{
	if (e->fps >= 1 / 60.0f)
	{
		if (e->fps > 0.025)
			e->fps = 0.025;
		e->move_speed = e->fps  * 12.0; //the constant value is in squares/second
		e->rot_speed = e->fps * ((double)M_PI / 1.1); //the constant value is in radians/second
	}
	if (e->flags & SIGN)
	{
		if (e->flags & TRAN_V)
			move_player(e, -1);
		else if (e->flags & TRAN_H)
			rotatate_view(e, e->dirX, e->planeX, 1);
	}
	else if (e->flags & TRAN_V)
		move_player(e, 1);
	else if (e->flags & TRAN_H)
		rotatate_view(e, e->dirX, e->planeX, -1);
	if (e->flags)
	{
		e->flags = 0;
		redraw_game(e);
	}
	return (0);
}
int my_key_pressed(int keycode, t_env *e)
{
	static clock_t start = 0, end = 0;

	start = end;
	end = clock();
	e->fps = (double)(end - start) / CLOCKS_PER_SEC;
	if (keycode == 124)
		e->flags |= TRAN_H;
	else if (keycode == 123)
		e->flags |= TRAN_H | SIGN;
	else if (keycode == 126)
		e->flags |= TRAN_V ;
	else if (keycode == 125)
		e->flags |= TRAN_V | SIGN;
	if (keycode == 49 && e->world_map[(int)(e->posX + e->dirX)][(int)(e->posY + e->dirY)] != 0)
	{
		int cur_col = e->world_map[(int)(e->posX + e->dirX)][(int)(e->posY + e->dirY)];
		if (cur_col > 4 && (cur_col - 5) % 8 == (e->last_color - 5) % 8 && cur_col != e->last_color)
		{
			e->values[cur_col - 5] = 0;
			e->values[e->last_color - 5] = 0;
			e->last_color = 0;
		}
		else if (e->last_color != 0)
		{
			e->values[e->last_color - 5] = 1;
			e->last_color = 0;
		}
		else
		{
			// worldMap[(int)(e->posX + e->dirX)][(int)(e->posY + e->dirY)] *= -1;
			e->values[cur_col - 5] = -1;
			e->last_color = cur_col;
		}
		printf("e->last_color %d\n", e->last_color);
		redraw_game(e);
	}

	return (0);
}
