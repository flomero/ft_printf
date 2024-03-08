/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:50:21 by flfische          #+#    #+#             */
/*   Updated: 2024/03/07 15:33:29 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief outputs the character c to the given file descriptor
 * @param c character to output
 * @param fd file descriptor to output to
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
