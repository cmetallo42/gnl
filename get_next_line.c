/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetallo <denerohin@yandex.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 18:58:37 by cmetallo          #+#    #+#             */
/*   Updated: 2020/07/31 11:35:48 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

char	*check_remaining(char *remaining, char **line)
{
	char	*ptn;

	ptn = NULL;
	if (remaining)
	{
		if ((ptn = ft_strchr(remaining, '\n')))
		{
			*ptn = '\0';
			*line = ft_strdup(remaining);
			ft_strcpy(remaining, ++ptn);
		}
		else
		{
			*line = ft_strdup(remaining);
			ft_strclr(remaining);
		}
	}
	else
		*line = ft_strnew(1);
	return (ptn);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			bwr;
	char		*ptn;
	static char	*remaining;
	char		*tmp;

	ptn = check_remaining(remaining, line);
	while (!ptn && (bwr = read(fd, buf, BUFF_SIZE)))
	{
		buf[bwr] = '\0';
		if ((ptn = ft_strchr(buf, '\n')))
		{
			*ptn = '\0';
			ptn++;
			remaining = ft_strdup(ptn);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	return (bwr || ft_strlen(remaining) || ft_strlen(*line) ? 1 : 0);
}

int		main(void)
{
	char	*line;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n\n", line);
	get_next_line(fd, &line);
	printf("%s\n\n", line);
}
