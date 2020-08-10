/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 11:04:14 by student           #+#    #+#             */
/*   Updated: 2020/08/08 08:56:29 by student          ###   ########.fr       */
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

char	*ft_strchr(char *str, int ch)
{
	int i;

	i = 0;
	while (str[i] != ch)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return (&str[i]);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*s2;

	len = 0;
	while (s1[len])
		len++;
	s2 = (char*)malloc(sizeof(char) * (len + 1));
	if (!(s2))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;

	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1) || !(s2))
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	j = -1;
	if (!(newstr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[++j])
		newstr[i++] = s2[j];
	newstr[i] = '\0';
	return (newstr);
}
