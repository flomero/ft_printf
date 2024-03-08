/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:05:17 by flfische          #+#    #+#             */
/*   Updated: 2024/03/09 00:45:40 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		size;
	int		i;
	va_list	args;

	va_start(args, format);
	i = 0;
	size = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			if (format[i] == '%')
				size += ft_putchar_fd('%', 1);
			else
				size += ft_parse_format(format, &i, args);
		}
		else
			size += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (size);
}
