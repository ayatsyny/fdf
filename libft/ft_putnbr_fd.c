/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 22:47:36 by ayatsyny          #+#    #+#             */
/*   Updated: 2016/12/04 16:35:04 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int num;
	unsigned int div;
	unsigned int count;

	div = 1;
	if (0 > fd && fd > 2)
		return ;
	num = n;
	if (n < 0)
	{
		num = -((unsigned int)n);
		write(fd, "-", 1);
	}
	count = ft_len_num(num);
	while (--count)
		div *= 10;
	while (div)
	{
		ft_putchar_fd(num / div + '0', fd);
		num %= div;
		div /= 10;
	}
}
