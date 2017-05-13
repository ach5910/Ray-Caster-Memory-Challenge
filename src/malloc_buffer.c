#include "wolf.h"

unsigned int **malloc_buffer(void)
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
