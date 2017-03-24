/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:19:27 by ayatsyny          #+#    #+#             */
/*   Updated: 2016/12/06 01:30:36 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	end;
	size_t	beg;
	char	*fresh;
	size_t	i;

	if (!s)
		return (NULL);
	end = ft_strlen(s) - 1;
	beg = 0;
	i = 0;
	while (ft_iswhitespace(s[beg]) && beg <= end)
		beg++;
	while (ft_iswhitespace(s[end]) && beg <= end)
		end--;
	if (!(fresh = (char *)malloc(end + 2 - beg)))
		return (NULL);
	if (beg != end && *s)
		while (beg <= end)
			fresh[i++] = s[beg++];
	fresh[i] = '\0';
	return (fresh);
}
