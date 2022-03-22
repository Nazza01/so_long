/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:20:10 by nervin            #+#    #+#             */
/*   Updated: 2022/03/21 03:04:51 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strchr(const char *s, int i);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*gnl_getline(int fd, char *buffer, char *back);
char		*gnl_extract(char *line);
char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);

#endif