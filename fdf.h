/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:59:07 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/03/16 16:59:12 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H
#define SIZ_H 1000
#define SIZ_W 1000
#define ALPHA 48.5
#define BETA 0.0
#define GAMMA 315.0
#define RELATION(digit, percentage) ((digit * percentage) / 100)
#include <math.h>
#include "mlx.h"
#include "./libft/libft.h"
#include "./libft/get_next_line.h"

typedef struct		s_xyz
{
	int				x;
	int				y;
	int				z;
}					t_xyz;

typedef struct 		s_oxyz
{
	double 			x;
	double 			y;
	double 			z;
}					t_oxyz;

typedef struct 		s_rgb
{
	char 			b;
	char 			g;
	char 			r;
}					t_rgb;

typedef struct		s_fdf
{
	t_xyz			coordinates;
	t_oxyz			oxyz;
	t_rgb			color;
	int 			new_line : 1;
//	int 			len_x;
//	int 			len_y;
	struct s_fdf	*next;
	struct s_fdf	*prev;
}					t_fdf;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char 			*buf_img;
	int 			size_line;
}					t_env;

/*
**  funcs for double list
*/

t_fdf	*create_node(t_xyz points);
//void	add_first(t_fdf *head, t_fdf *tail, t_fdf *new_node);
void	add_last(t_fdf **head, t_fdf **tail, t_fdf *new_node);

unsigned	count_dbl_lst_y(t_fdf **head);
unsigned	count_dbl_lst_x(t_fdf **head);


void	dbl_lstiter(t_fdf *lst, int revert, t_xyz xyz);


//void	draw_line(t_env *e, t_xyz xy0, t_xyz xy1);


void	init_env(t_env *env, char *name_prg);


void    put_px(int x, int y, t_rgb rgb, t_env *gen);
void segment(int x0, int y0, int x1, int y1, t_rgb rgb, t_env *gen);

//void	*change_x_y(t_fdf *node, t_xyz move_xyz);
//void	init_rgb(t_rgb *color);

#endif
