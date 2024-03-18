/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:06:36 by flfische          #+#    #+#             */
/*   Updated: 2024/03/18 09:54:12 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define CONVERSIONS "cspdiuxX"
# define FLAGS "#-+ 0"

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		alternative;
	int		space;
	int		plus;
}			t_flags;

typedef struct s_format
{
	t_flags	flags;
	int		width;
	int		precision;
	char	conversion;
}			t_format;

int			ft_printf(const char *format, ...);
t_format	*ft_parse_format(const char *format, int *i, va_list args);
int			ft_print_conversion(t_format *format_info, va_list args);
int			ft_print_format(const char *format, int *i, va_list args);
int			ft_get_flag(const char *format, int *i, t_flags *flags);
void		ft_skip_digits(const char *format, int *i);
t_format	*ft_alloc_format(void);

// Print functions
int			ft_print_char(t_format *format_info, va_list args);
int			ft_print_string(t_format *format_info, va_list args);
int			ft_print_decnum(t_format *format_info, va_list args);
int			ft_print_pointer(t_format *format, va_list args);
int			ft_print_unsigned(t_format *format_info, va_list args);

// Helper functions
int			ft_get_numlen(int i);
int			ft_power(int nb, int power);

#endif
