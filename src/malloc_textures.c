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

int **set_textures(void)
{
	int x;
	int y;
	int	**dest;

	dest = malloc_textures();
	x = -1;
	while (++x < TEXSIZE)
	{
		y = -1;
		while (++y < TEXSIZE)
		{
			int xorcolor = (x * 256 / TEXSIZE) ^ (y * 256 / TEXSIZE);
			int ycolor = y * 256 / TEXSIZE;
			int xycolor = y * 128 / TEXSIZE + x * 128 / TEXSIZE;
			double r = (double)x / TEXSIZE;
			int cr = (int)(43 * r + 255 * (1 - r));
			int cg = (int)(232 * r + 130 * (1 - r));
			int cb = (int)(191 * r + 53 * (1 - r));
			int color = (cr << 16) | (cg << 8) | cb;
			dest[0][TEXSIZE * y + x] = 0X7FFF00 * (x % 16 && y % 16); //flat red e->texture with black cross
			dest[1][TEXSIZE * y + x] = color;//* (x % 8 && y % 8) , ; //sloped greyscale128 + 240 * 128 + 65536 * 128;
			dest[2][TEXSIZE * y + x] = xorcolor + 256 * xorcolor + 65534 * xorcolor; //sloped yellow gradientxorcolor + 252 * xorcolor + 65536 * xorcolor; 
			dest[3][TEXSIZE * y + x] = xorcolor + 128 * xorcolor + 65536 * xorcolor; //xor greyscale254 * xycolor + 65536 * xycolor;
			dest[4][TEXSIZE * y + x] = 0xFF3300 * (x != y && x != TEXSIZE - y); //xor greenxycolor + 256 * xycolor + 65536 * xycolor;
			dest[5][TEXSIZE * y + x] = 0XFF1493;//0xFFFFFF;//65536 * 192 * (x % 16 && y % 16); //red bricks
			dest[6][TEXSIZE * y + x] = 0X8B4513;//254 * xycolor + 65536 * xycolor; //red gradient254 * xycolor + 65536 * xycolor;
			dest[7][TEXSIZE * y + x] = 0X9932CC;//256 * xorcolor; //flat grey e->texture
			dest[8][TEXSIZE * y + x] = 	0X006400;
			dest[9][TEXSIZE * y + x] = 0X00FFFF;
			dest[10][TEXSIZE * y + x] = 0X00008B;
			dest[11][TEXSIZE * y + x] = 0xDC143C;
			dest[12][TEXSIZE * y + x] = 0XADFF2F;
			dest[13][TEXSIZE * y + x] = 0XFF1493;//0xFFFFFF;//65536 * 192 * (x % 16 && y % 16); //red bricks
			dest[14][TEXSIZE * y + x] = 0X8B4513;//254 * xycolor + 65536 * xycolor; //red gradient254 * xycolor + 65536 * xycolor;
			dest[15][TEXSIZE * y + x] = 0X9932CC;//256 * xorcolor; //flat grey e->texture
			dest[16][TEXSIZE * y + x] = 0X006400;
			dest[17][TEXSIZE * y + x] = 0X00FFFF;
			dest[18][TEXSIZE * y + x] = 0X00008B;
			dest[19][TEXSIZE * y + x] = 0xDC143C;
			dest[20][TEXSIZE * y + x] = 0XADFF2F;
		}
	}
	return (dest);
}