/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:24:56 by ayatsyny          #+#    #+#             */
/*   Updated: 2016/12/04 15:59:35 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *copy_str;

	copy_str = (char *)malloc((ft_strlen(s1) + 1) * sizeof(*s1));
	if (!copy_str)
		return (NULL);
	return (ft_strcpy(copy_str, s1));
}
