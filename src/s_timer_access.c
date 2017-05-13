
#include "s_timer.h"

bool	f_timer_is_paused(const t_timer *v_this)
{
	return (v_this->v_paused == true);
}

bool	f_timer_is_started(const t_timer *v_this)
{
	return (v_this->v_started == true);
}
