/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:58:34 by flfische          #+#    #+#             */
/*   Updated: 2024/03/09 13:28:55 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_errors(char *base);

int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	int		len;
	long	n;
	int		size;

	size = 0;
	if (!check_errors(base))
		return (0);
	len = ft_strlen(base);
	n = nbr;
	if (n < 0)
	{
		n = -n;
		size += ft_putchar_fd('-', 1);
	}
	if (n >= len)
	{
		size += ft_putnbr_base(n / len, base);
		size += ft_putnbr_base(n % len, base);
	}
	else
	{
		size += ft_putchar_fd(base[n], 1);
	}
	return (size);
}

static int	check_errors(char *base)
{
	int	len;
	int	i;
	int	j;

	len = ft_strlen(base);
	if (len < 2)
		return (0);
	i = 0;
	while (i < len)
	{
		if (!(base[i] >= 32 && base[i] <= 126) || base[i] == '+'
			|| base[i] == '-' || base[i] == ' ')
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
