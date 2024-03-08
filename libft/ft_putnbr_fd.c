/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:57:59 by flfische          #+#    #+#             */
/*   Updated: 2024/03/09 00:39:57 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief outputs the integer n to the given file descriptor
 * @param n integer to output
 * @param fd file descriptor to output to
 * @return number of bytes written
 */
int	ft_putnbr_fd(int n, int fd)
{
	int		div;
	char	c;
	int		size;

	size = 0;
	div = 1;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		size += ft_putchar_fd('-', fd);
		n = -n;
	}
	while (n / div > 9)
		div = div * 10;
	while (div > 0)
	{
		c = (n / div) + '0';
		n = n - ((n / div) * div);
		size += ft_putchar_fd(c, fd);
		div = div / 10;
	}
	return (size);
}
