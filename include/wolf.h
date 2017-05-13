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
# include <time.h>
# include <stdio.h>
# include <stdbool.h>
# include <stddef.h>
# include <sys/time.h>
# define WIDTH		800
# define HEIGHT		640
# define MAPWIDTH	24
# define MAPHEIGHT	24
# define TRAN_H		0x01
# define TRAN_V		0x02
# define SIGN		0x04
# define TEXSIZE	64
# define START		0x01
# define PLAYING	0x02
# define GAMEOVER	0x04

typedef struct		s_vec2
{
	double			x;
	double			y;
}					t_vec2;

typedef struct		s_timer
{
	int				started;
	struct timeval	start;
}					t_timer;

typedef struct		s_tex_colors
{
	int				xorcolor;
	int				ycolor;
	int				xycolor;
	int				transition_color;
}					t_tex_colors;

typedef struct		s_map
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_y;
	double			delta_x;
	double			perp_wall_dist;
	double			rpx;
	double			rpy;
	double			wallx;
	double			floor_x_wall;
	double			floor_y_wall;
	double			dist_wall;
	double			dist_player;
	double			cur_dist;
	double			weight;
	int				tex_num;
	int				tex_y;
	int				tex_x;
	int				draw_start;
	int				draw_end;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				side;
	int				hit;
	int				line_height;
	unsigned int	color;
}					t_map;

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

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*img;
	int				*values;
	int				**world_map;
	int				**texture;
	unsigned int	flags;
	unsigned int	game_state;
	double			pos_x;
	int				last_color;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
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

t_env				*init_environment(void);
t_env				*init_parameters(t_env *e);
t_env				*init_grid(t_env *e);
t_img				*init_image(t_env *e);

t_map				init_map(t_env *e, int x);
t_map				check_if_hit(t_map map, t_env *e);
t_map				determine_line_size(t_map map);
t_map				calc_distances(t_env *e, t_map map);
t_map				floor_casting(t_map map);
t_map				get_wallx(t_map map);
t_map				get_texture_x(t_map map);
t_map				set_floor_variables(t_map map);

void				fill_texture_buffer(t_map map, t_env *e, int x);
void				free_environment(t_env *e);
void				put_pixel_img(t_env *e, int i, int j, int color);
void				draw_floor(t_map map, t_env *e, int x);
void				rotate_view(t_env *e, double dir_x, double plane_x, int s);
void				move_player(t_env *e, int s);
void				draw_map(t_env *e, t_map map);
void				update_timer(t_env *e);
void				fps(t_env *e);
void				get_top_scores(t_env *e);
void				draw_game_start(t_env *e);
void				draw_game_over(t_env *e);
void				free_scores(char **score);
void				free_image(t_env *e);
void				set_top_scores(t_env *e, char *score);
void				check_for_match(t_env *e);
void				timer_start(t_timer *t);

int					main(int argc, char **argv);
int					usage(void);
int					valid_player(char *player);
int					my_key_pressed(int keycode, t_env *e);
int					**malloc_textures();
int					**set_textures(void);
int					*init_box_states(void);
int					*randomize_boxes(void);
int					my_key_pressed(int k, t_env *e);
int					redraw_game(t_env *e);
int					expose_hook(t_env *e);
int					my_loop_hook(t_env *e);
int					exit_hook(t_env *e);
int					redraw_game(t_env *e);
int					exit_hook(t_env *e);
int					is_started(t_timer *t);

size_t				get_ticks(t_timer *t);

double				determine_wall_distance(t_env *e, t_map map);
double				delta_dist_y(double ray_dir_y, double ray_dir_x);
double				delta_dist_x(double ray_dir_y, double ray_dir_x);

#endif
