/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:26:28 by bebuber           #+#    #+#             */
/*   Updated: 2024/04/03 17:50:19 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion_check(const char *c, va_list args, int *count)
{
	if (*c == 'c')
		return (ft_putchar(va_arg(args, int), count));
	else if (*c == 's')
		return (ft_putstr(va_arg(args, char *), count));
	else if (*c == 'd' || *c == 'i')
		return (ft_putnbr(va_arg(args, int), count));
	else if (*c == 'u')
		return (ft_putnbr(va_arg(args, unsigned int), count));
	else if (*c == '%')
		return (ft_putchar('%', count));
	else if (*c == 'X')
		return (ft_hexa(va_arg(args, unsigned int), 1, count));
	else if (*c == 'x')
		return (ft_hexa(va_arg(args, unsigned int), 0, count));
	else if (*c == 'p')
	{
		if (ft_putstr("0x", count) < 0)
			return (-1);
		return (ft_hexa(va_arg(args, unsigned long), 0, count));
	}
	else
		return (ft_putchar(*c, count));
}
