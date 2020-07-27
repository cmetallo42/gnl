/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetallo <denerohin@yandex.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 18:58:37 by cmetallo          #+#    #+#             */
/*   Updated: 2020/07/27 19:11:26 by cmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	get_next_line(int fd, char **line)
{
	return (0);
}

int main(void)
{
	char *line;
	int fd;

	fd = open("text.txt", O_RDONLY);
}
