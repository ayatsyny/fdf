/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:32:04 by ayatsyny          #+#    #+#             */
/*   Updated: 2016/12/04 05:15:35 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char	const *s, char (*f)(char))
{
	char	*fresh;
	size_t	len_s;
	size_t	i;

	i = -1;
	if (!s || !f)
		return (NULL);
	len_s = ft_strlen(s);
	fresh = (char *)malloc(len_s + 1);
	if (!fresh)
		return (NULL);
	while (++i < len_s)
		fresh[i] = f(s[i]);
	fresh[i] = '\0';
	return (fresh);
}
