/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 08:29:09 by ahunt             #+#    #+#             */
/*   Updated: 2017/01/16 08:29:12 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int	main(void)
{
	t_env *e;

	e = init_environment();
	e->posX = 22;
	e->posY = 20;  //x and y start position
	e->dirX = -1;
	e->dirY = 0; //initial direction vector
	e->planeX = 0;
	e->planeY = 0.66;
	redraw_game(e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_hook(e->win, 2, 0, my_key_pressed, e);
	mlx_loop_hook(e->mlx, my_loop_hook, e);
	mlx_loop(e->mlx);
	return (0);
}

int redraw_game(t_env *e)
{
	// e->posX = 22;
	// e->posY = 20;  //x and y start position
	// e->dirX = -1;
	// e->dirY = 0; //initial direction vector
	// e->planeX = 0;
	// e->planeY = 0.66; //the 2d raycaster version of camera plane
	int x;

	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame


	x = 0;
	while (x < WIDTH)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)WIDTH - 1; //x-coordinate in camera space
		double rayPosX = e->posX;
		double rayPosY = e->posY;
		double rayDirX = e->dirX + e->planeX * cameraX;
		double rayDirY = e->dirY + e->planeY * cameraX;
		//which box of the map we're in
		int mapX = (int)rayPosX;
		int mapY = (int)rayPosY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (rayPosX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (rayPosY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
		}
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (worldMap[mapX][mapY] > 0) hit = 1;
		}
		//Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
		if (side == 0) perpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
		else           perpWallDist = (mapY - rayPosY + (1 - stepY) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(HEIGHT / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + HEIGHT / 2;
		if(drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + HEIGHT / 2;
		if(drawEnd >= HEIGHT)drawEnd = HEIGHT - 1;

		//choose wall color
		int color = 0;
		switch(worldMap[mapX][mapY])
		{
			case 1:  color = side == 1 ? 0x7F0000 : 0xFF0000;  break; //red
			case 2:  color = side == 1 ? 0x7F00 : 0xFF00;  break; //green
			case 3:  color = side == 1 ? 0x7F : 0xFF;   break; //blue
			case 4:  color = side == 1 ? 0x7F7F7F : 0xFFFFFF ;  break; //white
			default: color = side == 1 ? 0x7F7F : 0xFFFF; break; //yellow
		}

		//give x and y sides different brightness
		// int r;
		// int g;
		// int b;
		// if (side == 1)
		// {
		// 	r = color & 0xFF0000;
		// 	g = color & 0xFF00;
		// 	b = color & 0xFF;
		// 	color = 0;
		// 	color |= (r / 2) | (g / 2) | (b / 2);
		// }

		//draw the pixels of the stripe as a vertical line
		// mlx_clear_window(e->mlx, e->win);
		verLine(e, x, drawStart, drawEnd, color);
		x++;
		//timing for input and FPS counter
		// oldTime = time;
		// time = getTicks();
		double frameTime = 0.016667;//= (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
		// printf("FPS= %f  %d\n",1.0 / frameTime, x); //FPS counter
		// redraw();
		// cls();

		//speed modifiers
		e->moveSpeed = frameTime * 20.0; //the constant value is in squares/second
		e->rotSpeed = frameTime * 7.0; //the constant value is in radians/second
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img->i_ptr, 0, 0);
	mlx_destroy_image(e->mlx, e->img->i_ptr);
	e->img->i_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	return (0);
}

int expose_hook(t_env *e)
{
	redraw_game(e);
	return (0);
}

int my_loop_hook(t_env *e)
{
	if (e->flags & SIGN)
	{
		if (e->flags & TRAN_V)
		{
			//both camera direction and camera plane must be rotated
			double oldDirX = e->dirX;
			double oldDirY = e->dirY;
			e->dirX = oldDirX * cos(e->rotSpeed) - oldDirY * sin(e->rotSpeed);
			e->dirY = oldDirX * sin(e->rotSpeed) + oldDirY * cos(e->rotSpeed);
			double oldPlaneX = e->planeX;
			double oldPlaneY = e->planeY;
			e->planeX = oldPlaneX * cos(e->rotSpeed) - oldPlaneY * sin(e->rotSpeed);
			e->planeY = oldPlaneX * sin(e->rotSpeed) + oldPlaneY * cos(e->rotSpeed);
		}
		else if (e->flags & TRAN_H)
		{
			if(worldMap[(int)(e->posX + e->dirX * e->moveSpeed)][(int)(e->posY)] == 0) e->posX += e->dirX * e->moveSpeed;
			if(worldMap[(int)(e->posX)][(int)(e->posY + e->dirY * e->moveSpeed)] == 0) e->posY += e->dirY * e->moveSpeed;
		}
	}
	else if (e->flags & TRAN_V)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = e->dirX;
		double oldDirY = e->dirY;
		e->dirX = oldDirX * cos(-e->rotSpeed) - oldDirY * sin(-e->rotSpeed);
		e->dirY = oldDirX * sin(-e->rotSpeed) + oldDirY * cos(-e->rotSpeed);
		double oldPlaneX = e->planeX;
		double oldPlaneY = e->planeY;
		e->planeX = oldPlaneX * cos(-e->rotSpeed) - oldPlaneY * sin(-e->rotSpeed);
		e->planeY = oldPlaneX * sin(-e->rotSpeed) + oldPlaneY * cos(-e->rotSpeed);
	}
	else if (e->flags & TRAN_H)
	{
		if(worldMap[(int)(e->posX - e->dirX * e->moveSpeed)][(int)(e->posY)] == 0) e->posX -= e->dirX * e->moveSpeed;
		if(worldMap[(int)(e->posX)][(int)(e->posY - e->dirY * e->moveSpeed)] == 0) e->posY -= e->dirY * e->moveSpeed;
	}
	if (e->flags)
	{
		e->flags = 0;
		redraw_game(e);
	}
	return (0);
}
int my_key_pressed(int keycode, t_env *e)
{
	if (keycode == 124)
	{
		e->flags |= TRAN_V;
		//both camera direction and camera plane must be rotated
		// double oldDirX = e->dirX;
		// double oldDirY = e->dirY;
		// e->dirX = oldDirX * cos(-e->rotSpeed) - oldDirY * sin(-e->rotSpeed);
		// e->dirY = oldDirX * sin(-e->rotSpeed) + oldDirY * cos(-e->rotSpeed);
		// double oldPlaneX = e->planeX;
		// double oldPlaneY = e->planeY;
		// e->planeX = oldPlaneX * cos(-e->rotSpeed) - oldPlaneY * sin(-e->rotSpeed);
		// e->planeY = oldPlaneX * sin(-e->rotSpeed) + oldPlaneY * cos(-e->rotSpeed);
		// redraw_game(e);
	}
	else if (keycode == 123)
	{
		e->flags |= TRAN_V | SIGN;
		//both camera direction and camera plane must be rotated
		// double oldDirX = e->dirX;
		// double oldDirY = e->dirY;
		// e->dirX = oldDirX * cos(e->rotSpeed) - oldDirY * sin(e->rotSpeed);
		// e->dirY = oldDirX * sin(e->rotSpeed) + oldDirY * cos(e->rotSpeed);
		// double oldPlaneX = e->planeX;
		// double oldPlaneY = e->planeY;
		// e->planeX = oldPlaneX * cos(e->rotSpeed) - oldPlaneY * sin(e->rotSpeed);
		// e->planeY = oldPlaneX * sin(e->rotSpeed) + oldPlaneY * cos(e->rotSpeed);
		// redraw_game(e);
	}
	else if (keycode == 126)
	{
		e->flags |= TRAN_H | SIGN;
		// if(worldMap[(int)(e->posX + e->dirX * e->moveSpeed)][(int)(e->posY)] == 0) e->posX += e->dirX * e->moveSpeed;
		// if(worldMap[(int)(e->posX)][(int)(e->posY + e->dirY * e->moveSpeed)] == 0) e->posY += e->dirY * e->moveSpeed;
		// redraw_game(e);
	}
	else if (keycode == 125)
	{
		e->flags |= TRAN_H;
		// if(worldMap[(int)(e->posX - e->dirX * e->moveSpeed)][(int)(e->posY)] == 0) e->posX -= e->dirX * e->moveSpeed;
		// if(worldMap[(int)(e->posX)][(int)(e->posY - e->dirY * e->moveSpeed)] == 0) e->posY -= e->dirY * e->moveSpeed;
		// redraw_game(e);
	}
	return (0);
}
