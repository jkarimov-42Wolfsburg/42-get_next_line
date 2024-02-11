/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarimov <jkarimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:10:54 by jkarimov          #+#    #+#             */
/*   Updated: 2024/02/11 16:56:46 by jkarimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# include <unistd.h>
# include <stdlib.h>

char				*get_next_line(int fd);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
void				*ft_calloc(size_t count, size_t size);
void				ft_bzero(void *dest, size_t n);

#endif
