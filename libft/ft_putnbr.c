/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:41:41 by ayatsyny          #+#    #+#             */
/*   Updated: 2016/12/04 16:34:15 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	num;
	unsigned int	div;
	unsigned int	count;

	num = n;
	div = 1;
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else if (n < 0)
	{
		num = -((unsigned int)n);
		write(1, "-", 1);
	}
	count = ft_len_num(num);
	while (--count)
		div *= 10;
	while (div)
	{
		ft_putchar(num / div + '0');
		num %= div;
		div /= 10;
	}
}
