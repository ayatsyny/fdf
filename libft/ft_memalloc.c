/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:17:03 by ayatsyny          #+#    #+#             */
/*   Updated: 2016/12/04 15:38:32 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*array;
	size_t	i;

	i = -1;
	array = malloc(size);
	if (!array)
		return (NULL);
	while (++i < size)
		((char*)array)[i] = 0;
	return (array);
}
