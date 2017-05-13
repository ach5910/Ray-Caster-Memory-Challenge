#include "wolf.h"

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
