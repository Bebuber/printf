/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:08:30 by bebuber           #+#    #+#             */
/*   Updated: 2024/04/03 11:08:55 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long n, int *count)
{
	char	c;

	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_putstr("-2147483648", count));
		else if (write(1, "-", 1) < 0)
			return (-1);
		(*count)++;
		n = -n;
	}
	if (n >= 10)
	{
		if (ft_putnbr(n / 10, count) < 0)
			return (-1);
	}
	c = (n % 10 + '0');
	if (write(1, &c, 1) < 0)
		return (-1);
	(*count)++;
	return (1);
}

int	ft_un_int(unsigned int nb, int *count)
{
	long long	n;

	n = (long long)nb;
	return (ft_putnbr(n, count));
}
