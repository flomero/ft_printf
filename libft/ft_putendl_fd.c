/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:55:15 by flfische          #+#    #+#             */
/*   Updated: 2024/03/09 00:38:49 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief outputs the string s to the given file descriptor
 * followed by a newline
 * @param s string to output
 * @param fd file descriptor to output to
 */
int	ft_putendl_fd(char *s, int fd)
{
	int	size;

	size = ft_putstr_fd(s, fd);
	size += ft_putchar_fd('\n', fd);
	return (size);
}
