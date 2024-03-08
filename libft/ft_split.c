/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:09:27 by flfische          #+#    #+#             */
/*   Updated: 2024/03/07 15:35:54 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_del(const char *s, char del)
{
	int	size;

	size = 0;
	while (s[size] && s[size] != del)
		size++;
	return (size);
}

static int	ft_count_substr(char const *s, char del)
{
	size_t	count;
	size_t	i;
	int		was_del;

	i = 0;
	count = 0;
	was_del = 1;
	while (s[i])
	{
		if (s[i] != del)
		{
			if (was_del)
				count++;
			was_del = 0;
		}
		else
			was_del = 1;
		i++;
	}
	return (count);
}

static char	*ft_strcpy_del(char *dest, const char *src, char del)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != del)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strdup_del(const char *src, char del)
{
	char	*dest;

	dest = (char *)malloc(ft_strlen_del(src, del) + 1);
	if (dest == NULL)
		return (NULL);
	ft_strcpy_del(dest, src, del);
	return (dest);
}

/**
 * @brief Allocates (with malloc(3)) and returns an array of strings obtained by
 * splitting ’s’ using the character ’c’ as a delimiter. The array must be
 * ended by a NULL pointer.
 * @param s The string to split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split.
 */
char	**ft_split(char const *s, char c)
{
	size_t	str_count;
	size_t	i;
	char	**arr;

	str_count = ft_count_substr(s, c);
	arr = malloc((str_count + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < str_count)
	{
		while (*s == c)
			s++;
		arr[i] = ft_strdup_del(s, c);
		if (arr[i] == NULL)
		{
			while (i > 0)
				free(arr[--i]);
			free(arr);
			return (NULL);
		}
		s += ft_strlen(arr[i++]);
	}
	arr[i] = NULL;
	return (arr);
}
