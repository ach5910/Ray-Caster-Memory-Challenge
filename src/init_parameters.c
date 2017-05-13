#include "wolf.h"

t_env *init_parameters(t_env *e)
{
	e->posX = 12;
	e->posY = 12;  //x and y start position
	e->dirX = -1;
	e->dirY = 0;
	e->planeX = 0;
	e->planeY = 0.66;
	e->rot_speed = 0.016666 * 1.25;
	e->move_speed = 0.016666 * 3 ;
	e->fps = 0.0f;
	e->last_color = 0;
	e->time = 150;
	e->blocks = 16;
	e->time_left = 20;
	e->game_state = START;
	e->values = init_box_states();
	e->texture = set_textures();
	e = init_grid(e);
	return (e);
}
