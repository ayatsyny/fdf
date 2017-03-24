/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:49:08 by ayatsyny          #+#    #+#             */
/*   Updated: 2016/12/04 00:08:18 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	const *content, size_t content_size)
{
	t_list	*fresh;

	fresh = (t_list *)malloc(sizeof(t_list));
	if (!fresh)
		return (NULL);
	fresh->next = NULL;
	if (!content || !content_size)
	{
		fresh->content = NULL;
		fresh->content_size = 0;
		return (fresh);
	}
	fresh->content = malloc(content_size);
	if (!fresh->content)
		return (NULL);
	fresh->content_size = content_size;
	ft_memmove(fresh->content, content, content_size);
	return (fresh);
}
