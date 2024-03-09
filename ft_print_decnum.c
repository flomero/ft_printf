/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 03:26:45 by flfische          #+#    #+#             */
/*   Updated: 2024/03/09 03:52:03 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_numlen(int i)
{
	int	size;

	size = 1;
	while (i / 10 >= 10)
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

int	ft_print_decnum(t_format *format_info, va_list args)
{
	int	size;
	int	num;
	int	numlen;

	size = 0;
	num = va_arg(args, int);
	numlen = ft_get_numlen(num);
	ft_printf("test");
	if (format_info->flags.minus)
	{
		if (format_info->flags.plus && num >= 0)
			size += ft_putchar_fd('+', 1);
		if (num < 0)
			size += ft_putchar_fd('-', 1);
		while (format_info->precision-- > numlen)
			size += ft_putchar_fd('0', 1);
		while (num / ft_power(10, numlen) > 0)
		{
			size += ft_putchar_fd("0123456789"[num % (numlen * 10)], 1);
			num = num - (num / ft_power(10, numlen)) * ft_power(10, numlen);
		}
	}
	return (size);
}
