/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:50:15 by ayatsyny          #+#    #+#             */
/*   Updated: 2016/12/06 02:01:20 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_index_beg_word(char const *s, char c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len && s[i] == c)
		i++;
	return (i);
}

static size_t	get_index_end_word(char const *s, char c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len && s[i] != c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	size_t			end_index;
	unsigned int	words;
	size_t			len;
	char			**str;

	i = -1;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	words = ft_count_words(s, c);
	if (!(str = (char **)malloc((words + 1) * sizeof(char *))))
		return (NULL);
	while (++i < words)
	{
		s += get_index_beg_word(s, c, len);
		end_index = get_index_end_word(s, c, len);
		if (!(str[i] = (char *)malloc((end_index + 1) * sizeof(char))))
			return (NULL);
		ft_memmove(str[i], s, end_index);
		str[i][end_index] = '\0';
		s += end_index;
	}
	str[i] = NULL;
	return (str);
}
