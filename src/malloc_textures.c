#include "wolf.h"

int **malloc_textures()
{
	int i;
	int **temp;

	temp = (int**)malloc(sizeof(int*) * 21);
	i = -1;
	while (++i < 21)
		temp[i] = (int*)malloc(sizeof(int) * TEXSIZE * (TEXSIZE + 1));
	return (temp);
}

int **set_hidden_textures(int **dest, int x, int y)
{
	dest[5][TEXSIZE * y + x] = 0XFF1493;
	dest[6][TEXSIZE * y + x] = 0X8B4513;
	dest[7][TEXSIZE * y + x] = 0X9932CC;
	dest[8][TEXSIZE * y + x] = 	0X006400;
	dest[9][TEXSIZE * y + x] = 0X00FFFF;
	dest[10][TEXSIZE * y + x] = 0X00008B;
	dest[11][TEXSIZE * y + x] = 0xDC143C;
	dest[12][TEXSIZE * y + x] = 0XADFF2F;
	dest[13][TEXSIZE * y + x] = 0XFF1493;
	dest[14][TEXSIZE * y + x] = 0X8B4513;
	dest[15][TEXSIZE * y + x] = 0X9932CC;
	dest[16][TEXSIZE * y + x] = 0X006400;
	dest[17][TEXSIZE * y + x] = 0X00FFFF;
	dest[18][TEXSIZE * y + x] = 0X00008B;
	dest[19][TEXSIZE * y + x] = 0xDC143C;
	dest[20][TEXSIZE * y + x] = 0XADFF2F;
	return (dest);
}

void	set_tex_colors(t_tex_colors *tc, int x, int y)
{
	double	r;
	int		cr;
	int		cg;
	int		cb;

	tc->xorcolor = (x * 256 / TEXSIZE) ^ (y * 256 / TEXSIZE);
	tc->ycolor = y * 256 / TEXSIZE;
	tc->xycolor = y * 128 / TEXSIZE + x * 128 / TEXSIZE;
	r = (double)x / TEXSIZE;
	cr = (int)(43 * r + 255 * (1 - r));
	cg = (int)(232 * r + 130 * (1 - r));
	cb = (int)(191 * r + 53 * (1 - r));
	tc->transition_color = (cr << 16) | (cg << 8) | cb;
}

int **set_textures(void)
{
	int				x;
	int				y;
	int				**dest;
	t_tex_colors	tc;

	dest = malloc_textures();
	x = -1;
	while (++x < TEXSIZE)
	{
		y = -1;
		while (++y < TEXSIZE)
		{
			set_tex_colors(&tc, x, y);
			dest[0][TEXSIZE * y + x] = 0X7FFF00 * (x % 16 && y % 16);
			dest[1][TEXSIZE * y + x] = tc.transition_color;
			dest[2][TEXSIZE * y + x] = tc.xorcolor + 256 * tc.xorcolor +
				65534 * tc.xorcolor;
			dest[3][TEXSIZE * y + x] = tc.xorcolor + 128 * tc.xorcolor +
				65536 * tc.xorcolor;
			dest[4][TEXSIZE * y + x] = 0xFF3300 * (x != y && x != TEXSIZE - y);
			// dest[5][TEXSIZE * y + x] = 0XFF1493;
			// dest[6][TEXSIZE * y + x] = 0X8B4513;
			// dest[7][TEXSIZE * y + x] = 0X9932CC;
			// dest[8][TEXSIZE * y + x] = 	0X006400;
			// dest[9][TEXSIZE * y + x] = 0X00FFFF;
			// dest[10][TEXSIZE * y + x] = 0X00008B;
			// dest[11][TEXSIZE * y + x] = 0xDC143C;
			// dest[12][TEXSIZE * y + x] = 0XADFF2F;
			// dest[13][TEXSIZE * y + x] = 0XFF1493;
			// dest[14][TEXSIZE * y + x] = 0X8B4513;
			// dest[15][TEXSIZE * y + x] = 0X9932CC;
			// dest[16][TEXSIZE * y + x] = 0X006400;
			// dest[17][TEXSIZE * y + x] = 0X00FFFF;
			// dest[18][TEXSIZE * y + x] = 0X00008B;
			// dest[19][TEXSIZE * y + x] = 0xDC143C;
			// dest[20][TEXSIZE * y + x] = 0XADFF2F;
			dest = set_hidden_textures(dest, x, y);
		}
	}
	return (dest);
}