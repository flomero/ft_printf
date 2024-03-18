/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:30:10 by flfische          #+#    #+#             */
/*   Updated: 2024/03/18 09:59:17 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_print_uns_minus(t_format *format_info, unsigned int num, int numlen)
{
	int	size;

	size = 0;
	while (format_info->precision-- > numlen)
		size += ft_putchar_fd('0', 1);
	if (num == 0 && format_info->precision == -1)
		return (size);
	size += ft_putnbr_fd(num, 1);
	while (format_info->width-- > numlen)
		size += ft_putchar_fd(' ', 1);
	return (size);
}

int	ft_print_unsigned(t_format *format_info, va_list args)
{
	unsigned int	num;
	int				numlen;
	int				size;

	num = va_arg(args, unsigned int);
	numlen = ft_get_numlen(num);
	size = 0;
	if (format_info->flags.minus)
		size += ft_print_uns_minus(format_info, num, numlen);
	else
	{
		while (format_info->width-- > numlen)
			size += ft_putchar_fd(' ', 1);
		while (format_info->precision-- > numlen)
			size += ft_putchar_fd('0', 1);
		if (num == 0 && format_info->precision == -1)
			return (size);
		size += ft_putnbr_base(num, "0123456789");
	}
	return (size);
}
