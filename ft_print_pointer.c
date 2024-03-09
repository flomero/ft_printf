/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:57:02 by flfische          #+#    #+#             */
/*   Updated: 2024/03/09 13:27:40 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen_base(unsigned long long n, int base)
{
	int	len;

	len = 1;
	while (n >= (unsigned long long)base)
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

int	ft_print_pointer(t_format *format, va_list args)
{
	unsigned long long	pointer;
	int					size;

	pointer = va_arg(args, unsigned long long);
	size = ft_numlen_base(pointer, 16) + 2;
	if (format->precision > size - 2)
		size = format->precision + 2;
	if (format->precision == 0 && pointer == 0)
		size = 2;
	if (format->flags.minus)
	{
		ft_putstr_fd("0x", 1);
		ft_putnchr_fd('0', format->precision - size + 2, 1);
		if (!(format->precision == 0 && pointer == 0))
			ft_putnbr_base(pointer, "0123456789abcdef");
		ft_putnchr_fd(' ', format->width - size, 1);
	}
	else
	{
		ft_putnchr_fd(' ', format->width - size, 1);
		ft_putstr_fd("0x", 1);
		ft_putnchr_fd('0', format->precision - size + 2, 1);
		if (!(format->precision == 0 && pointer == 0))
			ft_putnbr_base(pointer, "0123456789abcdef");
	}
	return (size);
}
