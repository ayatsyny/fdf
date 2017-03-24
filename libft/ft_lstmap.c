/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 22:47:59 by ayatsyny          #+#    #+#             */
/*   Updated: 2016/12/05 20:59:30 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	head = f(ft_lstnew(lst->content, lst->content_size));
	if (!head)
		return (NULL);
	fresh = head;
	while ((lst = lst->next))
	{
		fresh->next = f(ft_lstnew(lst->content, lst->content_size));
		fresh = fresh->next;
		if (!fresh)
			return (NULL);
	}
	free(fresh);
	return (head);
}
