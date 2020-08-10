/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 11:16:15 by student           #+#    #+#             */
/*   Updated: 2020/08/08 11:02:29 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char			*ft_strcpy(char *dst, const char *src);
int				get_next_line(int fd, char **line);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s1);
int				from_buf(char *buf, char **remaining, char **ptn, char **line);
char			*ft_strchr(char *str, int ch);
size_t			ft_strlen(const char *str);
char			*check_remaining(char **remaining, char **line);

#endif
