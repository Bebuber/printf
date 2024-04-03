/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:08:16 by bebuber           #+#    #+#             */
/*   Updated: 2024/04/03 15:40:22 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned long address, int chr, int *count)
{
	char	c;

	if (address >= 16)
	{
		if (ft_hexa(address / 16, chr, count) < 0)
			return (-1);
	}
	if (chr == 0)
		c = "0123456789abcdef"[address % 16];
	else if (chr == 1)
		c = "0123456789ABCDEF"[address % 16];
	if (write(1, &c, 1) < 0)
		return (-1);
	(*count)++;
	return (1);
}
