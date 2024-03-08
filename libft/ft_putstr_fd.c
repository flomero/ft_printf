/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:52:58 by flfische          #+#    #+#             */
/*   Updated: 2024/03/09 00:37:06 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief outputs the string s to the given file descriptor
 * @param s string to output
 * @param fd file descriptor to output to
 * @return number of bytes written
 */
int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (*s)
	{
		i += ft_putchar_fd(*s, fd);
		s++;
	}
	return (i);
}
