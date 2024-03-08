/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:06:36 by flfische          #+#    #+#             */
/*   Updated: 2024/03/09 00:45:15 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define CONVERSIONS "cspdiuxX"
# define FLAGS "-0.*# +"

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	precision;
	int	width;
	int	alternative;
	int	space;
	int	plus;
}		t_flags;

int		ft_printf(const char *format, ...);
int		ft_parse_format(const char *format, int *i, va_list args);

#endif
