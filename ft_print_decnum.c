/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 03:26:45 by flfische          #+#    #+#             */
/*   Updated: 2024/03/09 12:50:06 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (num < 0 && num != LONG_MIN)
	{
		size += ft_putchar_fd('-', 1);
		num = -num;
	}
	while (format_info->precision-- > numlen)
		size += ft_putchar_fd('0', 1);
	if (num == 0)
		size += ft_putchar_fd('0', 1);
	else
	{
		size += ft_putnbr_fd(num, 1);
	}
	while (format_info->width-- > numlen)
		size += ft_putchar_fd(' ', 1);
	return (size);
}

int	ft_print_decnum_nominus(t_format *format_info, long long num, int numlen)
{
	int	size;

	size = 0;
	while (format_info->width-- > numlen)
		size += ft_putchar_fd(' ', 1);
	if (format_info->flags.plus && num >= 0)
		size += ft_putchar_fd('+', 1);
	if (num < 0 && num != LONG_MIN)
	{
		size += ft_putchar_fd('-', 1);
		num = -num;
	}
	while (format_info->precision-- > numlen)
		size += ft_putchar_fd('0', 1);
	if (num == 0)
		size += ft_putchar_fd('0', 1);
	else
		size += ft_putnbr_fd(num, 1);
	return (size);
}

int	ft_print_decnum(t_format *format_info, va_list args)
{
	int			size;
	long long	num;
	int			numlen;

	size = 0;
	num = va_arg(args, long long);
	numlen = ft_get_numlen(num);
	if (format_info->flags.minus)
		size += ft_print_decnum_minus(format_info, num, numlen);
	else
		size += ft_print_decnum_nominus(format_info, num, numlen);
	return (size);
}