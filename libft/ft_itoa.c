/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:37:56 by ayatsyny          #+#    #+#             */
/*   Updated: 2016/12/06 04:48:34 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int a)
{
	unsigned int	count;
	char			*str_num;
	unsigned int	aa;

	aa = a;
	count = 0;
	if (a < 0)
	{
		aa = -((unsigned int)a);
		count++;
	}
	count += ft_len_num(aa);
	str_num = ft_strnew((size_t)count);
	if (!str_num)
		return (NULL);
	while (count)
	{
		str_num[--count] = aa % 10 + '0';
		if (!(aa /= 10))
			break ;
	}
	if (!str_num[0])
		str_num[0] = '-';
	return (str_num);
}
