/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:38:58 by ayatsyny          #+#    #+#             */
/*   Updated: 2016/12/04 15:49:46 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*buff;
	size_t			i;

	i = -1;
	buff = (unsigned char *)malloc(len + 1);
	if (!buff)
		return (dst);
	while (++i < len)
		buff[i] = ((unsigned char *)src)[i];
	i = -1;
	while (++i < len)
		((unsigned char *)dst)[i] = buff[i];
	free(buff);
	return (dst);
}
