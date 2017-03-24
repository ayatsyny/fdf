
#include "fdf.h"

unsigned	count_dbl_lst_y(t_fdf **head)
{
	t_fdf		*p;
	unsigned	count;

	p = *head;
	count = 0;
	while (p)
	{
		if (p->new_line)
			count++;
		p = p->next;
	}
	return (count);
}

unsigned	count_dbl_lst_x(t_fdf **head)
{
	t_fdf		*p;
	unsigned	count;

	p = *head;
	count = 0;
	while (p)
	{
		count++;
		if (p->new_line)
			break ;
		p = p->next;
	}
	return (count);
}

//void	*change_x_y(t_fdf *node, t_xyz move_xyz)
//{
//	node->coordinates += move_xyz;
//}