
#include "fdf.h"

//void	draw_line(t_env *e, t_xyz xy0, t_xyz xy1)
//{
//	int		y;
//	int		x;
//	double	k;
//	double	d;
//
//	k = ((double)(xy1.y - xy0.y)) / (xy1.x - xy0.x);
//	d = 2 * k - 1;
//	y = xy0.y;
//	mlx_pixel_put(e->mlx, e->win, xy0.x, xy0.y, 0x00FFFFFF);
//	x = xy0.x - 1;
//	while (++x <= xy1.x)
//	{
//		if (d > 0)
//		{
//			d += 2 * k - 2;
//			y++;
//		}
//		else
//			d += 2 * k;
//		mlx_pixel_put(e->mlx, e->win, x, y, 0x00FFFFFF);
//	}
//}

void segment(int x0, int y0, int x1, int y1, t_rgb rgb, t_env *gen)
{
	int dx;
	int dy;
	int sx;
	int sy;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	sx = x1 >= x0 ? 1 : -1;
	sy = y1 >= y0 ? 1 : -1;
	if (dy <= dx)
	{
		int d = (dy << 1) - dx;
		int d1 = dy << 1;
		int d2 = (dy -dx) << 1;
		put_px(x0, y0, rgb, gen);
		// putpixel(x0, y0, color)
		for(int x = x0 + sx, y = y0, i = 1; i <= dx; i++, x += sx)
		{
			if (d > 0)
			{
				d += d2;
				y += sy;
			}
			else
				d += d1;
			put_px(x, y, rgb, gen);
			//putpixel(x, y, color)
		}
	}
	else
	{
		int d = (dx << 1) - dy;
		int d1 = dx << 1;
		int d2 = (dx -dy) << 1;
		// putixel(x0, y0, color)
		for(int y = y0 + sy, x = x0, i = 1; i <= dy; i++, y += sy)
		{
			if (d > 0)
			{
				d += d2;
				x += sx;
			}
			else
				d += d1;
			put_px(x, y, rgb, gen);
			// putpixel(x, y, color);
		}
	}
}