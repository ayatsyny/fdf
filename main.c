/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:57:26 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/03/16 16:57:28 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <zconf.h>
#include "fdf.h"


void	error_exit(char	*str)
{
	write(1, "error:\n\t", 8);
	ft_putendl(str);
	exit(1);
}

//int		count_words(char *s, char c)
//{
//	int				i;
//	unsigned int	count;
//
//	i = -1;
//	count = 0;
//	while (s[++i])
//	{
//		if (s[i] == c)
//			continue ;
//		while (s[i] != c && s[i])
//			i++;
//		if (s[i - 1] != c)
//			count++;
//	}
//	return (count);
//}

void write_strs(char **s)
{
	int i;

	i = -1;
	while (s[++i])
		printf("[%s] ", s[i]);
	printf("\n");
}


void	pars_data(t_fdf	**head, t_fdf **tail, int fd)
{
	t_xyz	point_on_map;
	int		end_x;
	char	*line;
	char 	**strs;
	t_fdf	*node;

	point_on_map.y = -1;
	while (get_next_line(fd, &line) > 0 && ++point_on_map.y >= 0)
	{
		end_x = ft_count_words(line, ' ');
		strs = ft_strsplit(line, ' ');
//		write_strs(strs);
		point_on_map.x = -1;
		while (++point_on_map.x < end_x)
		{
			point_on_map.z = ft_atoi(strs[point_on_map.x]);
			node = create_node(point_on_map);
			add_last(head, tail, node);

		}
		node->new_line = 1;
	}
}

void	print_res(t_fdf **head)
{
	t_fdf *p;

	p = *head;
	while (p)
	{
		printf("x = %d y = %d z = %d", p->coordinates.x, p->coordinates.y, p->coordinates.z);
		if (p->new_line)
			printf(" new line \n\n\n");
		printf("\n");
		p = p->next;
	}
}



//void	check_pars_data(t_fdf *head)
//{
//	t_fdf *item;
//
//}

int	my_key_funct(int keycode, t_env *e)
{
	printf("key event %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int mouse_hook(int button, int x, int y, t_env *e)
{
	printf("mouse: %d (%d:%d)\n", button, x, y);
	return (0);
}

void	exmp_draw(void *mlx, void *win)
{
	int x;
	int y;

	y = 50;
//	sleep(2);
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
//			usleep(500);
			x++;
		}
		y++;
	}
}

int 	expose_hook(t_env *e)
{
	exmp_draw(e->mlx, e->win);
	return (0);
}



//void	test_bresenham(t_env *e)
//{
//	t_xyz xy0;
//	t_xyz xy1;
//
//	xy0.x = 50;
//	xy0.y = 50;
//
//	xy1.x = 700;
//	xy1.y = 700;
////	draw_line(e, xy0, xy1);
//}

//
//int main(int argc, char **argv)
//{
//	int fd;
//	t_fdf *head;
//	t_fdf *tail;
//	char *f_name;
//	t_env test;
//
//	head = NULL;
//	tail = NULL;
//	if (argc != 2)
//		error_exit("is not a valid number of arguments");
//	if ((fd = open(argv[1], O_RDONLY)) == -1)
//		error_exit(strerror(errno));
//	f_name = ft_strchr(argv[1], '.');
//	if (f_name && !ft_strequ(f_name, ".fdf"))
//		error_exit("file must have the extension *.fdf");
//	pars_data(&head, &tail, fd);
//	print_res(&head);
//	test.mlx = mlx_init();
//	test.win = mlx_new_window(test.mlx, 1200, 1200, "FdF");
//	test_bresenham(&test);
//	mlx_key_hook(test.win, my_key_funct, &test);
////	mlx_expose_hook(test.win, expose_hook, &test);
////	mlx_mouse_hook(test.win, mouse_hook, &test);
//	mlx_loop(test.mlx);
//	return (0);
//}

//void    put_px(int x, int y, s_rgb *rgb, s_gen *general)
//{
//	if (put_checker(x, y, general))
//	{
//		IMG_A[y * SIZ_L + x * 4] = rgb->b;
//		IMG_A[y * SIZ_L + x * 4 + 1] = rgb->g;
//		IMG_A[y * SIZ_L + x * 4 + 2] = rgb->r;
//	}
//}


void    put_px(int x, int y, t_rgb rgb, t_env *gen)
{
	if (x >= 0 && x <= SIZ_W && y >= 0 && y <= SIZ_H)
	{
		gen->buf_img[y * gen->size_line + x * 4] = rgb.b;
		gen->buf_img[y * gen->size_line + x * 4 + 1] = rgb.g;
		gen->buf_img[y * gen->size_line + x * 4 + 2] = rgb.r;
	}
}

void	moving_central(t_fdf **head)
{
	t_fdf *p;
	t_xyz xyz;
	t_xyz central;

	p = *head;
//	xyz.y = 10;
	xyz.y = SIZ_H / (int)count_dbl_lst_y(head);
	xyz.x = SIZ_W / (int)count_dbl_lst_x(head);
	xyz.z = 0;
	central.y = RELATION(SIZ_H, 25);
	central.x = RELATION(SIZ_W, 25);
//	central.y = SIZ_H / 2;
//	central.x = SIZ_W / 2;
	central.z = 0;
	dbl_lstiter(p, 1, central);

//	dbl_lstiter(p, 1, );
}

//void	test_print_dot(t_fdf **head, t_env *env)
//{
//	t_fdf *p;
//
//	p = *head;
//	while (p)
//	{
//		put_px(p->coordinates.x, p->coordinates.y, p->color, env);
//		p = p->next;
//	}
//}

void 	test_draw(t_fdf **head, t_env *env)
{
	t_fdf *p;
	t_xyz xyz;
	t_xyz tmp;
	int i;

	p = *head;
	xyz.y = SIZ_H / ((int)count_dbl_lst_y(head) + 2);
	xyz.x = SIZ_W / ((int)count_dbl_lst_x(head) + 2);
	if (p)
	{
		p->coordinates.x = xyz.x;
		p->coordinates.y = xyz.y;
		tmp = p->coordinates;
	}
	i = 0;
	while (p)
	{
		put_px(tmp.x, tmp.y, p->color, env);
		if (!(p = p->next))
			break ;
		tmp.x = i != 0 ? RELATION(SIZ_H, 25) : tmp.x + xyz.x;
		p->coordinates.x = tmp.x;
		p->coordinates.y = tmp.y;
		tmp.y += i;
		i = p->new_line && p->next ? xyz.y : 0;
	}
}

int 	change_base_cordinate(t_fdf **head)
{
	t_fdf *p;
	int m;
	int len_x;
	int len_y;
	int riz;
	int i;

	p = *head;
	i = 1;
	len_x = count_dbl_lst_x(head);
	len_y = count_dbl_lst_y(head);
	m = RELATION((SIZ_W >= SIZ_H ? SIZ_W : SIZ_H), 80) / (len_x > len_y ? len_x : len_y);
	riz = RELATION((SIZ_W >= SIZ_H ? SIZ_W : SIZ_H), 10) + ((len_x > len_y ? len_x : len_y) - 1) * m;
	riz = (int)lround((RELATION((SIZ_W >= SIZ_H ? SIZ_W : SIZ_H), 80) - riz) / 2);
	while (p)
	{
		p->coordinates.x -= len_x/2;
		p->coordinates.y -= len_y/2;
		p->oxyz.x = p->coordinates.x * m + riz * i;
		p->new_line ? i = 1 : i++;
		p->oxyz.y = p->coordinates.y * m;
		p = p->next;
	}
	return (riz);
}

void	change_new_xyz(t_fdf **head)
{
	t_fdf *p;
	int m;
	int len_x;
	int len_y;
	int riz;
	int i;

	p = *head;
	i = 1;
	len_x = count_dbl_lst_x(head);
	len_y = count_dbl_lst_y(head);
	m = RELATION((SIZ_W >= SIZ_H ? SIZ_W : SIZ_H), 80) / (len_x > len_y ? len_x : len_y);
	riz = RELATION((SIZ_W >= SIZ_H ? SIZ_W : SIZ_H), 10) + ((len_x > len_y ? len_x : len_y) - 1) * m;
	riz = (int)lround((RELATION((SIZ_W >= SIZ_H ? SIZ_W : SIZ_H), 80) - riz) / 2);
	while (p)
	{
		p->oxyz.x = p->oxyz.x * m + riz * i;
		p->new_line ? i = 1 : i++;
		p->oxyz.y = p->oxyz.y * m;
		p = p->next;
	}
}

//void 	change_field(t_fdf **head)
//{
//	int		m;
//	t_fdf	*p;
//
//	m = (SIZ_W >= SIZ_H ? SIZ_W : SIZ_H) / (count_dbl_lst_x(head) > count_dbl_lst_y(head) ? count_dbl_lst_x(head) : count_dbl_lst_y(head));
//	p = *head;
//	while (p)
//	{
//		p->oxyz.x = p->coordinates.x * m;
//		p->oxyz.y = p->coordinates.y * m;
//		p = p->next;
//	}
//}

void	draw_dom(t_fdf **head, int x, int y)
{
	t_fdf *p;
	int  i = 0;

	p = *head;
	while (p)
	{
		p->oxyz.x += x;
		p->oxyz.y += y;
		printf("%d. x = %f y = %f \n", i++, p->oxyz.x, p->oxyz.y);
		if (p->new_line)
		{
			printf("new line \n\n\n");
			i = 0;
		}
//		put_px((int)p->oxyz.x, (int)p->oxyz.y, p->color, env);
		p = p->next;
	}
}

void 	draw_line(t_fdf **head, t_env *env)
{
	t_fdf *p;
	t_fdf *tmp;
	int count;

	p = *head;
	tmp = *head;
	count = 0;
	while (p)
	{
		if (count)
		{
			segment((int)tmp->oxyz.x, (int)tmp->oxyz.y, (int)p->oxyz.x, (int)p->oxyz.y, p->color, env);
			tmp = tmp->next;
		}
		if (!p->new_line && p->next)
			segment((int)p->oxyz.x, (int)p->oxyz.y, (int)p->next->oxyz.x, (int)p->next->oxyz.y, p->color, env);
		else
			count++;
		p = p->next;
	}
}

void draw_3d(t_fdf **head)
{
	t_fdf *p;
	double rad_alpha;
	double rad_beta;
	double rad_gamma;

	rad_alpha = ALPHA * M_PI / 180.0;
	rad_beta = BETA * M_PI / 180.0;
	rad_gamma = GAMMA * M_PI / 180.0;
	p = *head;

	while (p)
	{
		p->oxyz.x = p->coordinates.x * cos(rad_gamma) + p->coordinates.y * sin(rad_gamma);
		p->oxyz.y = -p->coordinates.x * sin(rad_gamma) + p->coordinates.y * cos(rad_gamma);
		p->oxyz.z = p->coordinates.z;

		p->oxyz.y = p->coordinates.y * cos(rad_alpha) + p->coordinates.z * sin(rad_alpha);
		p->oxyz.z = -p->coordinates.y * sin(rad_alpha) + p->coordinates.z * cos(rad_alpha);

		p->oxyz.x = p->coordinates.x * cos(rad_beta) + p->coordinates.z * sin(rad_beta);
		p->oxyz.z = -p->coordinates.x * sin(rad_beta) + p->coordinates.z * cos(rad_beta);
		p = p->next;
	}
}

void mastab(t_fdf **head, float k)
{
	t_fdf *p;

	p = *head;
	while (p)
	{
		p->oxyz.x /= k;
		p->oxyz.y /= k;
		p->oxyz.z /= k;
		p = p->next;
	}
}

void matrix_povorot(t_oxyz vector, float angle, t_oxyz *xyz)
{
	double m[3][3];
	double cos_one;
	double cos_s;
	double sin_s;

	cos_s = cos(angle);
	cos_one = 1 - cos_s;
	sin_s = sin(angle);
	m[0][0] = cos_s + cos_one * vector.x * vector.x;
	m[0][1] = cos_one * vector.y * vector.x + sin_s * vector.z;
	m[0][2] = cos_one * vector.z * vector.x - sin_s * vector.y;

	m[1][0] = cos_one * vector.x * vector.y - sin_s * vector.z;
	m[1][1] = cos_s + cos_one * vector.y * vector.y;
	m[1][2] = cos_one * vector.z * vector.y + sin_s * vector.x;

	m[2][0] = cos_one * vector.x * vector.z + sin_s * vector.y;
	m[2][1] = cos_one * vector.y * vector.z - sin_s * vector.x;
	m[2][2] = cos_s + cos_one * vector.z * vector.z;

	xyz->x = xyz->x * m[0][0] + xyz->y * m[0][1] + xyz->z * m[0][2];
	xyz->y = xyz->x * m[1][0] + xyz->y * m[1][1] + xyz->z * m[1][2];
	xyz->z = xyz->x * m[2][0] + xyz->y * m[2][1] + xyz->z * m[2][2];
}


void cccc(t_fdf **head)
{
	t_fdf *p;
	t_oxyz xyz;

	xyz.x = 1;
	xyz.y = 0;
	xyz.z = 0;
	p = *head;
	while (p)
	{
		matrix_povorot(xyz, 45, &p->oxyz);
		p = p->next;
	}
}

//void 	draw(t_fdf **head, t_env *gen)
//{
//	t_fdf *p;
//	int x;
//	int y;
//
//	p = *head;
//	while (p)
//	{
//		x = p->coordinates.x;
//		y = p->coordinates.y;
//		if (!(p = p->next))
//			break ;
//		segment(x, y, p->coordinates.x, p->coordinates.y, p->color, gen);
//	}
//}

int main(int argc, char **argv)
{
	int fd;
	t_fdf *head;
	t_fdf *tail;
	char *f_name;
	t_env test;

	//
	char 	*str_img;
	int		bits_per_pixel;
//	int 	size_line;
	int 	endian;

	head = NULL;
	tail = NULL;
//	printf("%d %d %d\n", bits_per_pixel, size_line, endian);
	if (argc != 2)
		error_exit("is not a valid number of arguments");
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		error_exit(strerror(errno));
	f_name = ft_strchr(argv[1], '.');
	if (f_name && !ft_strequ(f_name, ".fdf"))
		error_exit("file must have the extension *.fdf");
	pars_data(&head, &tail, fd);
	print_res(&head);
	test.mlx = mlx_init();
	test.win = mlx_new_window(test.mlx, SIZ_W, SIZ_H, "FdF");
//	init_env(&test, argv[0]);
	test.img = mlx_new_image(test.mlx, SIZ_W, SIZ_H);
	test.buf_img = mlx_get_data_addr(test.img, &bits_per_pixel, &test.size_line, &endian);
	printf("len buf %d %d %d \n", bits_per_pixel, test.size_line, endian);
	change_base_cordinate(&head);
//	matrix_povorot(xyz, 270);

	t_xyz xyz;
	xyz.x = SIZ_W / 2;
	xyz.y = SIZ_H / 2;
	xyz.z = 0;
	draw_dom(&head, (int)xyz.x, (int)xyz.y);
//	draw_3d(&head);
//	change_new_xyz(&head);
//	draw_dom(&head);
//	mastab(&head, 0.1);
	cccc(&head);
	draw_line(&head, &test);
//	moving_central(&head);
//	printf("%d %d %d\n", bits_per_pixel, size_line, endian);
//	if (test.buf_img)
//		printf("yes [%p], %s\n", &str_img, test.buf_img);
//	test_draw(&head, &test);
//	draw(&head, &test);
//	test_print_dot(&head, &test);
	mlx_put_image_to_window(test.mlx, test.win, test.img, 0, 0);
//	test_bresenham(&test);
	mlx_key_hook(test.win, my_key_funct, &test);
//	mlx_expose_hook(test.win, expose_hook, &test);
//	mlx_mouse_hook(test.win, mouse_hook, &test);
	mlx_loop(test.mlx);
	return (0);
}