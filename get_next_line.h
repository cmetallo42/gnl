/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 11:16:15 by student           #+#    #+#             */
/*   Updated: 2020/07/31 11:45:56 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char			*ft_strcpy(char *dst, const char *src);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_calloc(size_t num, size_t size);
int				get_next_line(int fd, char **line);
void			ft_strclr(char *s);
char			*ft_strnew(size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strdup(const char *s1);
void			*ft_memcpy(void *d, const void *s, size_t n);
char			*ft_strchr(char *str, int ch);
size_t			ft_strlen(const char *str);

#endif
