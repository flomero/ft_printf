/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:57:02 by flfische          #+#    #+#             */
/*   Updated: 2024/03/18 12:01:40 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_numlen_base(unsigned long n, int base)
{
	int	len;

	len = 1;
	while (n >= (unsigned long)base)
	{
		n /= base;
		len++;
	}
	return (len);
}

int	ft_putnchr_fd(char c, int n, int fd)
{
	int	size;

	size = 0;
	while (n-- > 0)
		size += ft_putchar_fd(c, fd);
	return (size);
}

int	ft_print_pointer_hex(unsigned long pointer)
{
	int	size;

	size = 0;
	if (pointer >= 16)
	{
		size += ft_print_pointer_hex(pointer / 16);
		size += ft_putchar_fd("0123456789abcdef"[pointer % 16], 1);
	}
	else
		size += ft_putchar_fd("0123456789abcdef"[pointer], 1);
	return (size);
}

int	ft_print_pointer_minus(t_format *format, unsigned long pointer)
{
	int	size;

	size = 0;
	ft_putstr_fd("0x", 1);
	ft_putnchr_fd('0', format->precision - size + 2, 1);
	if (!(format->precision == 0 && pointer == 0))
		ft_print_pointer_hex(pointer);
	ft_putnchr_fd(' ', format->width - size, 1);
	return (size);
}

int	ft_print_pointer(t_format *format, va_list args)
{
	unsigned long	pointer;
	int				size;

	pointer = (unsigned long)va_arg(args, long);
	size = ft_numlen_base(pointer, 16) + 2;
	if (format->precision > size - 2)
		size = format->precision + 2;
	if (format->precision == 0 && pointer == 0)
		size = 2;
	if (format->flags.minus)
		size += ft_print_pointer_minus(format, pointer);
	else
	{
		ft_putnchr_fd(' ', format->width - size, 1);
		ft_putstr_fd("0x", 1);
		ft_putnchr_fd('0', format->precision - size + 2, 1);
		if (!(format->precision == 0 && pointer == 0))
			ft_print_pointer_hex(pointer);
	}
	return (size);
}
