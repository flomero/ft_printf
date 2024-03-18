/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:05:17 by flfische          #+#    #+#             */
/*   Updated: 2024/03/18 10:08:40 by flfische         ###   ########.fr       */
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
			if (format[i] == '%' && i++)
				size += ft_putchar_fd('%', 1);
			else
				size += ft_print_format(format, &i, args);
		}
		else
			size += ft_putchar_fd(format[i++], 1);
	}
	va_end(args);
	return (size);
}

int	ft_print_format(const char *format, int *i, va_list args)
{
	t_format	*format_info;

	format_info = ft_parse_format(format, i, args);
	if (format_info == NULL)
		return (0);
	if (format[*i] == '\0')
		return (0);
	format_info->conversion = format[*i];
	(*i)++;
	return (ft_print_conversion(format_info, args));
}

int	ft_print_conversion(t_format *format_info, va_list args)
{
	int	size;

	size = 0;
	if (format_info->conversion == 'c')
		size = ft_print_char(format_info, args);
	else if (format_info->conversion == 's')
		size = ft_print_string(format_info, args);
	else if (format_info->conversion == 'd' || format_info->conversion == 'i')
		size = ft_print_decnum(format_info, args);
	else if (format_info->conversion == 'p')
		size = ft_print_pointer(format_info, args);
	else if (format_info->conversion == 'u')
		size = ft_print_unsigned(format_info, args);
	else if (format_info->conversion == 'x')
		size = ft_print_lowerhex(format_info, args);
	else if (format_info->conversion == 'X')
		size = ft_print_upperhex(format_info, args);
	free(format_info);
	return (size);
}
