/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 03:13:22 by flfische          #+#    #+#             */
/*   Updated: 2024/03/09 03:16:47 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(t_format *format_info, va_list args)
{
	int		size;
	char	*str;

	size = 0;
	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	if (format_info->flags.minus)
		size += ft_putstr_fd(str, 1);
	while ((size_t)format_info->width > ft_strlen(str))
	{
		if (format_info->flags.zero && !format_info->flags.minus)
			size += ft_putchar_fd('0', 1);
		else
			size += ft_putchar_fd(' ', 1);
		format_info->width--;
	}
	if (!format_info->flags.minus)
		size += ft_putstr_fd(str, 1);
	return (size);
}
