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
	t_img			*img_l;
	t_img			*img;
	double			zoom;
	int				**texture;
	unsigned int	**buffer;
	unsigned int	flags;
	double			posX;
	int				past;
	int				cur_sec;
	double			posY;
	double			dirX;
	double			dirY;
	double			old_time;
	double			cur_time;
	double			frame_time;
	double			planeX;
	double			planeY;
	double			move_speed;
	double			rot_speed;
	double			fps;
}					t_env;

extern int worldMap[mapHeight][mapWidth];

int	main(void);
t_env	*init_environment(void);
t_img	*init_image(t_env *e);
void    verLine(t_env *e, int x, int drawStart, int drawEnd, int color);
void    draw_lines_y(t_env *e, t_vec2 *p1, t_vec2 * p2, int color);
void    put_pixel_img(t_env *e, int i, int j, int color);
t_line	*get_line_params_y(t_env *e, t_vec2 *p1, t_vec2 *p2);
int my_key_pressed(int k, t_env *e);
int redraw_game(t_env *e);
int expose_hook(t_env *e);
int		my_loop_hook(t_env *e);
void draw_buffer(t_env *e, unsigned int buf[640][800]);
void draw_map(t_env *e,int wmap[24][24], t_map map);
void put_pixel_img_mini(t_env *e, int i, int j, int color, int n);

#endif
