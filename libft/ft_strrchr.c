/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 23:51:16 by ayatsyny          #+#    #+#             */
/*   Updated: 2016/12/04 16:10:51 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*end_str;
	unsigned int	st_str;

	st_str = ft_strlen(s);
	end_str = (char *)(s + st_str);
	while (st_str && *end_str != (unsigned char)c)
	{
		end_str--;
		st_str--;
	}
	if (!st_str && *end_str != (unsigned char)c)
		return (NULL);
	return ((char *)end_str);
}
