/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:26:56 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/03/16 17:27:00 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


//void	add_first(t_fdf *head, t_fdf *tail, t_fdf *new_node)
//{
//	new_node->next = head;
//	new_node->prev = NULL;
//	if (head)
//		head->prev = new_node;
//	if (!tail)
//		tail = head;
//}

void	add_last(t_fdf **head, t_fdf **tail, t_fdf *new_node)
{

	new_node->prev = *tail;
	new_node->next = NULL;
	if (!*tail)
		*tail = new_node;
	else
	{
		(*tail)->next = new_node;
		*tail = new_node;
	}
	if (!*head)
		*head = *tail;
}

t_fdf	*create_node(t_xyz points)
{
	t_fdf *new;

	if (!(new = (t_fdf *)malloc(sizeof(t_fdf))))
		return (NULL);
//	new->coordinates.x = points.y;
//	new->coordinates.y = points.x;
//	new->coordinates.z = points.x;
	new->coordinates = points;
	new->color.b = 0xFF;
	new->color.g = 0xFF;
	new->color.r = 0xFF;
//	init_rgb(new->color);
	new->new_line = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	dbl_lstiter(t_fdf *lst, int revert, t_xyz move)
{
		while (lst)
		{
			lst->coordinates.x += move.x;
			lst->coordinates.y += move.y;
			lst->coordinates.z += move.z;
			if (revert == 1)
				lst = lst->next;
			else if (revert == -1)
				lst = lst->prev;
		}
}

//void	dbl_lstiter2(t_fdf *lst, int revert, t_xyz move)
//{
//	int f;
//
//	f = 0;
//	while (lst)
//	{
//		lst->coordinates.x += move.x;
//		if (lst->new_line)
//			f++;
//		if (f)
//		lst->coordinates.y += move.y;
//		if (revert == 1)
//			lst = lst->next;
//		else if (revert == -1)
//			lst = lst->prev;
//	}
//}


//void	add_after(t_fdf *head, t_fdf *tail, t_fdf *p, t_fdf *new_node)
//{
//	if (!p->next)
//		add_last(head, tail, new_node);
//	else
//	{
//		new_node->next = p->next;
//		new_node->prev = p;
//		p->next->prev = new_node;
//		p->next = new_node;
//	}
//}