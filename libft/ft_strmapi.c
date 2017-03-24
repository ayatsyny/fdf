/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:52:12 by ayatsyny          #+#    #+#             */
/*   Updated: 2016/11/28 18:37:29 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*fresh;
	char	temp;
	size_t	len_s;
	size_t	i;

	i = -1;
	temp = '\0';
	if (!s || !f)
		return (NULL);
	len_s = ft_strlen(s);
	if (!len_s)
		return (NULL);
	fresh = (char *)malloc(len_s + 1);
	if (!fresh)
		return (NULL);
	while (++i < len_s)
	{
		temp = f((unsigned int)i, (char)s[i]);
		if (!temp)
			return (NULL);
		fresh[i] = temp;
	}
	fresh[i] = '\0';
	return (fresh);
}
