/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:50:21 by flfische          #+#    #+#             */
/*   Updated: 2024/03/19 22:25:08 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief outputs the character c to the given file descriptor
 * @param c character to output
 * @param fd file descriptor to output to
 * @return number of bytes written
 */
int	ft_putchar_fd(char c, int fd)
{
	int	status;
	int	*error;

	status = 0;
	error = get_write_error();
	if (*error != 1)
	{
		status = write(fd, &c, 1);
		if (status == -1)
		{
			*error = 1;
		}
	}
	return (status);
}

int	*get_write_error(void)
{
	static int	status;

	return (&status);
}

void	set_write_error(int status)
{
	int	*error;

	error = get_write_error();
	*error = status;
}
