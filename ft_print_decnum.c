/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 03:26:45 by flfische          #+#    #+#             */
/*   Updated: 2024/03/19 18:17:16 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_get_numlen(int i)
{
	int	size;

	size = 1;
	if (i == INT_MIN)
		return (11);
	if (i == 0)
		return (1);
	if (i < 0)
	{
		size++;
		i = -i;
	}
	while (i >= 10)
	{
		i /= 10;
		size++;
	}
	return (size);
}

int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_power(nb, power - 1));
}

int	ft_print_decnum_minus(t_format *format_info, long long num, int numlen)
{
	int	size;

	size = 0;
	if (format_info->flags.plus && num >= 0)
		size += ft_putchar_fd('+', 1);
	if (num < 0)
	{
		size += ft_putchar_fd('-', 1);
		format_info->precision++;
		num = -num;
	}
	while (format_info->precision-- > numlen)
		size += ft_putchar_fd('0', 1);
	if (num == 0)
		size += ft_putchar_fd('0', 1);
	else if (num == (long)INT_MAX + 1)
		size += ft_putstr_fd("2147483648", 1);
	else
		size += ft_putnbr_fd(num, 1);
	while (size < format_info->width)
		size += ft_putchar_fd(' ', 1);
	return (size);
}

int	ft_print_decnum_nominus(t_format *format_info, long long num, int numlen)
{
	int	size;

	size = 0;
	if (num < 0)
		format_info->precision++;
	if (format_info->flags.plus && num >= 0)
		format_info->width--;
	while (format_info->width > format_info->precision
		&& format_info->precision > 0 && format_info->width-- > numlen)
		size += ft_putchar_fd(' ', 1);
	while (!format_info->flags.zero && format_info->width-- > numlen
		&& ((format_info->precision < 0 || (num < 0
					&& format_info->precision == 0))
			|| format_info->precision < numlen))
		size += ft_putchar_fd(' ', 1);
	if (format_info->flags.plus && num >= 0)
		size += ft_putchar_fd('+', 1);
	if (num < 0)
	{
		size += ft_putchar_fd('-', 1);
		num = -num;
	}
	while (format_info->flags.zero && format_info->width-- > numlen)
	{
		size += ft_putchar_fd('0', 1);
		format_info->precision--;
	}
	while (format_info->precision-- > numlen)
		size += ft_putchar_fd('0', 1);
	if (num == 0)
		size += ft_putchar_fd('0', 1);
	else if (num == (long)INT_MAX + 1)
		size += ft_putstr_fd("2147483648", 1);
	else
		size += ft_putnbr_fd(num, 1);
	return (size);
}

int	ft_print_decnum(t_format *format_info, va_list args)
{
	int		size;
	long	num;
	int		numlen;

	size = 0;
	num = va_arg(args, int);
	numlen = ft_get_numlen(num);
	if (format_info->precision == 0 && num == 0)
	{
		while (format_info->width-- > 0)
			size += ft_putchar_fd(' ', 1);
		return (size);
	}
	if (num < 0)
		format_info->flags.space = 0;
	if (format_info->flags.space && !format_info->flags.plus)
	{
		format_info->width--;
		size += ft_putchar_fd(' ', 1);
	}
	if (format_info->flags.minus)
		size += ft_print_decnum_minus(format_info, num, numlen);
	else
		size += ft_print_decnum_nominus(format_info, num, numlen);
	return (size);
}
