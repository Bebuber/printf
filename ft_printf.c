/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:34:45 by bebuber           #+#    #+#             */
/*   Updated: 2024/04/03 17:58:49 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *c, ...)
{
	va_list	args;
	int		count;

	va_start (args, c);
	count = 0;
	while (*c)
	{
		if (*c == '%')
		{
			if (conversion_check(++c, args, &count) < 0)
				return (-1);
		}
		else if (ft_putchar(*c, &count) < 0)
			return (-1);
		c++;
	}
	va_end (args);
	return (count);
}
