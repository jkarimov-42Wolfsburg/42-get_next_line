/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarimov <jkarimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:05:24 by jkarimov          #+#    #+#             */
/*   Updated: 2024/02/11 22:52:22 by jkarimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

char				*get_next_line(int fd);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strchr(const char *s, int i);
size_t				ft_strlen(const char *s);
void				*ft_calloc(size_t count, size_t size);
void				ft_bzero(void *dest, size_t n);

#endif