
#include "s_timer.h"
#include <stddef.h>

void	f_timer_start(t_timer *v_this)
{
	v_this->v_started = true;
	v_this->v_paused = false;
	gettimeofday(&v_this->v_start, NULL);
}

void	f_timer_stop(t_timer *v_this)
{
	v_this->v_started = false;
	v_this->v_paused = false;
}

void	f_timer_pause(t_timer *v_this)
{
	struct timeval	tmp;

	if (v_this->v_started == true && v_this->v_paused == false)
	{
		v_this->v_paused = true;
		gettimeofday(&tmp, NULL);
		v_this->v_pause.tv_sec = tmp.tv_sec - v_this->v_start.tv_sec;
		v_this->v_pause.tv_usec = tmp.tv_usec - v_this->v_start.tv_usec;
	}
}

void	f_timer_unpause(t_timer *v_this)
{
	struct timeval	tmp;

	if (v_this->v_paused == true)
	{
		v_this->v_paused = false;
		gettimeofday(&tmp, NULL);
		v_this->v_start.tv_sec = tmp.tv_sec - v_this->v_pause.tv_sec;
		v_this->v_start.tv_usec = tmp.tv_usec - v_this->v_pause.tv_usec;
		v_this->v_pause.tv_sec = 0;
		v_this->v_pause.tv_usec = 0;
	}
}

size_t	f_timer_get_ticks(t_timer *v_this)
{
	struct timeval	tmp;

	if (v_this->v_started == false)
		return (0);
	if (v_this->v_paused == true)
	{
		return ((size_t)v_this->v_pause.tv_sec * 1000 +
						(size_t)v_this->v_pause.tv_usec / 1000);
	}
	gettimeofday(&tmp, NULL);
	return (((size_t)tmp.tv_sec * 1000 + (size_t)tmp.tv_usec / 1000) -
	((size_t)v_this->v_start.tv_sec * 1000 +
	(size_t)v_this->v_start.tv_usec / 1000));
}
