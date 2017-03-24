
#include "fdf.h"

//void	init_fdf(t_fdf *node)
//{
//	node->coordinates = 0;
//	node->
//}

//void	init_rgb(t_rgb *color)
//{
//
//}

void	init_env(t_env *env, char *name_prg)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, SIZ_H, SIZ_W, name_prg);
}