/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 11:04:14 by student           #+#    #+#             */
/*   Updated: 2020/07/31 12:31:07 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i += 1;
	}
	dst[i] = '\0';
	return (dst);
}

void	*ft_calloc(size_t num, size_t size)
{
	char	*mem;

	if (!(mem = malloc(num * size)))
		return (NULL);
	ft_memset(mem, 0, num * size);
	return (mem);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b1;

	b1 = (unsigned char *)b;
	i = 0;
	while (i != len)
	{
		b1[i] = c;
		i++;
	}
	return ((void *)b1);
}

char	*ft_strchr(char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i] != ch)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return (&str[i]);
}

void	ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*s2;

	len = ft_strlen(s1);
	if (!(s2 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(s2, s1, len + 1);
	return (s2);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (!(d = ft_calloc(sizeof(char), s1len + s2len + 1)))
		return (NULL);
	ft_memcpy(d, s1, s1len);
	ft_memcpy(d + s1len, s2, s2len);
	return (d);
}

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	unsigned char	*d1;
	unsigned char	*s1;
	size_t			i;

	d1 = (unsigned char*)d;
	s1 = (unsigned char*)s;
	i = 0;
	if (d == NULL && s == NULL)
		return (NULL);
	while (i != n)
	{
		d1[i] = s1[i];
		i++;
	}
	return (d1);
}

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}
