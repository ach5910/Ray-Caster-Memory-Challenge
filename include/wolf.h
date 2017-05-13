/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 08:33:08 by ahunt             #+#    #+#             */
/*   Updated: 2017/01/16 08:33:10 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "libft.h"
# include "mlx.h"
# include "s_timer.h"
# include <math.h>
#include <time.h>
#include <stdio.h>
// # include <mach/clock.h>
// # include <mach/mach.h>
# define WIDTH 800//512
# define HEIGHT 640//384
# define MINIW 120
# define MINIH 120
# define mapWidth 24
# define mapHeight 24
# define TRAN_H	0x01
# define TRAN_V	0x02
# define SIGN	0x04
#define TEXSIZE 64
# define START	0x01
# define PLAYING	0x02
# define GAMEOVER	0x04	

typedef struct		s_vec2
{
	double			x;
	double			y;
}					t_vec2;

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
	double	rpx;
	double	rpy;
	double	wallx;
	double	floor_x_wall;
	double	floor_y_wall;
	double	dist_wall;
	double	dist_player;
	double	cur_dist;
	double	weight;
	int		tex_num;
	int		tex_y;
	int		tex_x;
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

typedef struct		s_img
{
	void			*i_ptr;
	int				bpp;
	int				size_line;
	int				endian;
	char			*data;
	int				w;
	int				h;
}					t_img;

typedef struct		s_line
{
	double			dx;
	double			dy;
	double			p;
	double			i;
	double			j;
	double			j_incr;
	t_vec2			*end;
	t_vec2			*start;
}					t_line;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*img;
	int				*values;
	int				**world_map;
	int				**texture;
	unsigned int	**buffer;
	unsigned int	flags;
	unsigned int	game_state;
	double			posX;
	int				past;
	int				last_color;
	double			posY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
	double			move_speed;
	double			rot_speed;
	double			fps;
	int				time;
	t_timer			timer;
	int				time_left;
	int				blocks;
	char			*player;
	char			**top_scores;

}					t_env;
// extern int values[16]; //= {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
// extern int worldMap[mapHeight][mapWidth];

t_env	*init_environment(void);
t_env	*init_parameters(t_env *e);
t_env	*init_grid(t_env *e);
t_img	*init_image(t_env *e);

t_map	init_map(t_env *e, int x);
t_map	check_if_hit(t_map map, t_env *e);
t_map	determine_line_size(t_map map);
t_map	calc_distances(t_env *e, t_map map);
t_map	floor_casting(t_map map);
t_map	get_wallx(t_map map);
t_map	get_texture_x(t_map map);

void	fill_texture_buffer(t_map map,t_env *e, int x);
void	free_environment(t_env *e);
void    verLine(t_env *e, int x, int drawStart, int drawEnd, int color);
void    draw_lines_y(t_env *e, t_vec2 *p1, t_vec2 * p2, int color);
void    put_pixel_img(t_env *e, int i, int j, int color);
void	buffer_to_image(t_env *e, int x);
void	clear_buffer(t_env *e);
void	draw_floor(t_map map,t_env *e, int x);
void	rotate_view(t_env *e, double dir_x, double plane_x, int s);
void	move_player(t_env *e, int s);
void	draw_map(t_env *e, t_map map);
void	put_pixel_img_mini(t_env *e, int i, int j, int color, int n);
void	update_timer(t_env *e);
void	fps(t_env *e);
void	get_top_scores(t_env *e);
void	draw_game_start(t_env *e);
void	draw_game_over(t_env *e);
void	free_scores(t_env *e);
void	free_image(t_env *e);


t_line	*get_line_params_y(t_env *e, t_vec2 *p1, t_vec2 *p2);

int		main(int argc, char **argv);
int		my_key_pressed(int keycode, t_env *e);
int		**malloc_textures();
int		**set_textures(void);
int		*init_box_states(void);
int		my_key_pressed(int k, t_env *e);
int		redraw_game(t_env *e);
int		expose_hook(t_env *e);
int		my_loop_hook(t_env *e);
int		exit_hook(t_env *e);
int		get_array(int a, int b, int c, int d, int e);
int		redraw_game(t_env *e);
int		exit_hook(t_env *e);
int		expose_hook(t_env *e);
int		my_loop_hook(t_env *e);

double	determine_wall_distance(t_env *e, t_map map);
double	delta_dist_y(double ray_dir_y, double ray_dir_x);
double	delta_dist_x(double ray_dir_y, double ray_dir_x);

unsigned int	**malloc_buffer(void);

#endif
