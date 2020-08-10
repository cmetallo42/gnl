/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetallo <denerohin@yandex.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 18:58:37 by cmetallo          #+#    #+#             */
/*   Updated: 2020/08/08 11:01:26 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_remaining(char **remaining, char **line)
{
	char	*ptn;

	*line = NULL;
	ptn = NULL;
	if (*remaining)
	{
		if ((ptn = ft_strchr(*remaining, '\n')))
		{
			*ptn = '\0';
			if (!(*line = ft_strdup(*remaining)))
				return (NULL);
			ft_strcpy(*remaining, ++ptn);
		}
		else
		{
			*line = ft_strdup(*remaining);
			free(*remaining);
			*remaining = NULL;
		}
	}
	return (ptn);
}

int		from_buf(char *buf, char **remaining, char **ptn, char **line)
{
	char	*temp;

	if (!(*line))
		if (!(*line = ft_strdup("")))
			return (-1);
	if (((*ptn) = ft_strchr(buf, '\n')))
	{
		**ptn = '\0';
		temp = *remaining;
		(*ptn)++;
		if (!(*remaining = ft_strdup(*ptn)))
			return (-1);
		free(temp);
	}
	temp = *line;
	if (!(*line = ft_strjoin(*line, buf)))
		return (-1);
	free(temp);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			bwr;
	char		*ptn;
	static char	*remaining;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	ptn = check_remaining(&remaining, line);
	while (!ptn && (bwr = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		buf[bwr] = '\0';
		if (from_buf(buf, &remaining, &ptn, line) == -1)
			return (-1);
		if (bwr == 0)
			break ;
	}
	if (ptn)
		return (1);
	if (bwr <= 0)
	{
		free(remaining);
		remaining = NULL;
		return (bwr);
	}
	return (-1);
}
