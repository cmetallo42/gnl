/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetallo <denerohin@yandex.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 18:58:37 by cmetallo          #+#    #+#             */
/*   Updated: 2020/07/28 20:36:06 by cmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "/Users/cmetallo/Desktop/libft/libft.h"

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
		*line = "\0";
	return (ptn);
}

int	get_next_line(int fd, char **line)
{
	char	buf[10 + 1];
	int		bwr;
	char	*ptn;
	static char *remaining;

	ptn = check_remaining(remaining, line);
	while (!ptn && (bwr = read(fd, buf, 10)))
	{
		if ((ptn = ft_strchr(buf, '\n')))
		{
			*ptn = '\0';
			ptn++;
			remaining = ft_strdup(ptn);
		}
				
		buf[bwr] = '\0';
		*line = ft_strjoin(*line, buf);
	}
	return (0);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
    printf("%s\n", line);
	return (0);
}
