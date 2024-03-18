/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:01:14 by flfische          #+#    #+#             */
/*   Updated: 2024/03/18 10:27:41 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_lowerhex(t_format *format_info, va_list args)
{
	unsigned int	num;
	int				size;

	size = 0;
	num = (unsigned int)va_arg(args, int);
	if (format_info->flags.minus)
	{
		if (format_info->conversion)
			size += ft_putstr_fd("0x", 1);
		size += ft_putnbr_base(num, "0123456789abcdef");
	}
	else
	{
		if (format_info->flags.zero)
		{
			if (format_info->flags.alternative)
				size += ft_putstr_fd("0x", 1);
			size += ft_putnchr_fd('0', format_info->width - ft_get_numlen(num),
					1);
		}
		else
		{
			size += ft_putnchr_fd(' ', format_info->width - ft_get_numlen(num),
					1);
			if (format_info->flags.alternative)
				size += ft_putstr_fd("0x", 1);
		}
		size += ft_putnbr_base(num, "0123456789abcdef");
	}
	return (size);
}

int	ft_print_upperhex(t_format *format_info, va_list args)
{
	unsigned int	num;
	int				size;

	size = 0;
	num = (unsigned int)va_arg(args, int);
	if (format_info->flags.minus)
	{
		if (format_info->conversion)
			size += ft_putstr_fd("0X", 1);
		size += ft_putnbr_base(num, "0123456789ABCDEF");
	}
	else
	{
		if (format_info->flags.zero)
		{
			if (format_info->flags.alternative)
				size += ft_putstr_fd("0X", 1);
			size += ft_putnchr_fd('0', format_info->width - ft_get_numlen(num),
					1);
		}
		else
		{
			size += ft_putnchr_fd(' ', format_info->width - ft_get_numlen(num),
					1);
			if (format_info->flags.alternative)
				size += ft_putstr_fd("0X", 1);
		}
		size += ft_putnbr_base(num, "0123456789ABCDEF");
	}
	return (size);
}
