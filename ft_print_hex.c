/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:01:14 by flfische          #+#    #+#             */
/*   Updated: 2024/03/18 22:30:45 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_hexlen(unsigned int num)
{
	int	size;

	size = 1;
	while (num >= 16)
	{
		num /= 16;
		size++;
	}
	return (size);
}

int	ft_print_hex_minus(t_format *format_info, unsigned int num, char *base,
		char *prefix)
{
	int	size;

	size = 0;
	size += ft_putstr_fd(prefix, 1);
	size += ft_putnchr_fd('0', format_info->precision - ft_get_hexlen(num), 1);
	size += ft_putnbr_base(num, base);
	size += ft_putnchr_fd(' ', format_info->width - size, 1);
	return (size);
}

int	ft_print_hex(t_format *format_info, unsigned int num, char *base,
		char *prefix)
{
	int	size;

	size = 0;
	if (format_info->flags.minus)
		size += ft_print_hex_minus(format_info, num, base, prefix);
	else
	{
		if (format_info->precision > ft_get_hexlen(num))
			format_info->width -= format_info->precision - ft_get_hexlen(num);
		while (format_info->width > ft_get_hexlen(num) + (int)ft_strlen(prefix)
			+ size && !format_info->flags.zero && !format_info->flags.minus)
			size += ft_putchar_fd(' ', 1);
		while (format_info->precision-- > ft_get_hexlen(num))
			size += ft_putchar_fd('0', 1);
		if (format_info->flags.zero && format_info->precision < 0)
		{
			size += ft_putstr_fd(prefix, 1);
			size += ft_putnchr_fd('0', format_info->width - ft_get_hexlen(num)
					- ft_strlen(prefix), 1);
		}
		else
		{
			if (format_info->width > ft_get_hexlen(num))
				size += ft_putnchr_fd(' ', format_info->width
						- ft_get_hexlen(num) - size, 1);
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
	if (format_info->flags.alternative && num != 0)
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
	if (format_info->flags.alternative && num != 0)
		size += ft_print_hex(format_info, num, "0123456789ABCDEF", "0X");
	else
		size += ft_print_hex(format_info, num, "0123456789ABCDEF", "");
	return (size);
}
