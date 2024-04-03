/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:46:30 by bebuber           #+#    #+#             */
/*   Updated: 2024/04/03 15:47:02 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	conversion_check(const char *c, va_list args, int *count);
int	ft_putchar(char c, int *count);
int	ft_putstr(char *c, int *count);
int	ft_putnbr(long long n, int *count);
int	ft_un_int(unsigned int nb, int *count);
int	ft_hexa(unsigned long address, int chr, int *count);
int	ft_printf(const char *c, ...);

#endif