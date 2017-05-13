

#ifndef S_TIMER_H
# define S_TIMER_H

# include <stdbool.h>
# include <stddef.h>
# include <sys/time.h>

typedef struct		s_timer
{
	bool			v_paused;
	bool			v_started;
	struct timeval	v_start;
	struct timeval	v_pause;
}					t_timer;

# define D_TIMER(funct)	f_timer_##funct

void				f_timer_start(t_timer *v_this);
void				f_timer_stop(t_timer *v_this);
void				f_timer_pause(t_timer *v_this);
void				f_timer_unpause(t_timer *v_this);
size_t				f_timer_get_ticks(t_timer *v_this);
bool				f_timer_is_started(const t_timer *v_this);
bool				f_timer_is_paused(const t_timer *v_this);

#endif
