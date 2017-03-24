/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 01:40:50 by ayatsyny          #+#    #+#             */
/*   Updated: 2016/12/06 01:44:42 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_len_num(unsigned int a)
{
	unsigned int count;

	count = 0;
	if (a == 0)
		return (1);
	while (a && count++ < 10)
		a /= 10;
	return (count);
}
