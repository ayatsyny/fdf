/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:33:12 by ayatsyny          #+#    #+#             */
/*   Updated: 2016/12/05 04:37:49 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char	const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;
	char	*p_s;

	i = 0;
	p_s = (char *)s;
	if (!s || start > (unsigned)len || (size_t)start > ft_strlen(s)
		|| (int)start <= -1)
		return (NULL);
	fresh = (char *)malloc(len + 1);
	if (!fresh)
		return (NULL);
	p_s += start;
	while (p_s && i < len)
		fresh[i++] = *p_s++;
	fresh[i] = '\0';
	return (fresh);
}
