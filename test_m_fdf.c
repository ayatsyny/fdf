
#include "documents/minilibx/mlx.h"
#include <stdio.h>

int	my_key_funct(int keycode, void *mlx)
{
	(void)mlx;
	printf("key event %d\n", keycode);
	//mlx_pixel_put(mlx, 300, 300, 0xFF00FF);
	return (0);
}

int main()
{
	void	*mlx;
	void	*win;
	int 	x;
	int		y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x<150)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	// mlx_pixel_put(mlx, win, 200, 200, 0x00FFFFFF);
	mlx_key_hook(win, my_key_funct, mlx);
	mlx_loop(mlx);
}
