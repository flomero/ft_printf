/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:01:14 by flfische          #+#    #+#             */
/*   Updated: 2024/03/18 13:36:39 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(t_format *format_info, unsigned int num, char *base,
		char *prefix)
{
	int	size;

	size = 0;
	if (format_info->flags.minus)
	{
		size += ft_putstr_fd(prefix, 1);
		size += ft_putnbr_base(num, base);
	}
	else
	{
		if (format_info->flags.zero)
		{
			size += ft_putstr_fd(prefix, 1);
			size += ft_putnchr_fd('0', format_info->width - ft_get_numlen(num)
					- ft_strlen(prefix), 1);
		}
		else
		{
			size += ft_putnchr_fd(' ', format_info->width - ft_get_numlen(num)
					- ft_strlen(prefix), 1);
			size += ft_putstr_fd(prefix, 1);
		}
		size += ft_putnbr_base(num, base);
	}
	return (size);
}

int	ft_print_lowerhex(t_format *format_info, va_list args)
{
	unsigned int	num;
	int				size;

	size = 0;
	num = (unsigned int)va_arg(args, int);
	if (format_info->flags.alternative)
		size += ft_print_hex(format_info, num, "0123456789abcdef", "0x");
	else
		size += ft_print_hex(format_info, num, "0123456789abcdef", "");
	return (size);
}

int	ft_print_upperhex(t_format *format_info, va_list args)
{
	unsigned int	num;
	int				size;

	size = 0;
	num = (unsigned int)va_arg(args, int);
	if (format_info->flags.alternative)
		size += ft_print_hex(format_info, num, "0123456789ABCDEF", "0X");
	else
		size += ft_print_hex(format_info, num, "0123456789ABCDEF", "");
	return (size);
}
