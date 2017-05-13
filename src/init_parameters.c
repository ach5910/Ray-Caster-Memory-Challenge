#include "wolf.h"

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
	e->last_color = 0;
	e->timer = 100;
	e->blocks = 16;
	e->values = init_box_states();
	e->texture = set_textures();
	e->buffer = malloc_buffer();
	e = init_grid(e);
	return (e);
}
