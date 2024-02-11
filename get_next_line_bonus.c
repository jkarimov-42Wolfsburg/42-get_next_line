/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarimov <jkarimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:10:48 by jkarimov          #+#    #+#             */
/*   Updated: 2024/02/11 22:32:53 by jkarimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line(int fd, char *str)
{
	char	*buffer;
	int		byte_read;
	char	*temp;

	if (!str)
		str = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0 && !ft_strchr(buffer, '\n'))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (free (str), free (buffer), NULL);
		buffer[byte_read] = 0;
		temp = ft_strjoin(str, buffer);
		free(str);
		str = temp;
	}
	return (free(buffer), str);
}

char	*ft_line(char *store, int i)
{
	char	*s;

	i = 0;
	if (!store[i])
		return (NULL);
	while (store[i] && store[i] != '\n')
		i++;
	if (store[i] == '\n')
		i++;
	s = ft_calloc(i + 2, sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (store[i] && store[i] != '\n')
	{
		s[i] = store[i];
		i++;
	}
	if (store[i] && store[i] == '\n')
	{
		s[i++] = '\n';
	}
	return (s);
}

char	*ft_save_line(char *store)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (store[i] && store[i] != '\n')
		i++;
	if (!store[i])
		return (free(store), NULL);
	s = ft_calloc((ft_strlen(store) - i + 1), sizeof(char));
	if (!s)
		return (free(store), NULL);
	i++;
	j = 0;
	if (store[i] == '\0')
		return (free (s), free (store), NULL);
	while (store[i])
	{
		s[j] = store[i];
		j++;
		i++;
	}
	return (free (store), s);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	static char	*store[257];

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (0);
	store[fd] = ft_read_line(fd, store[fd]);
	if (!store[fd])
		return (NULL);
	line = ft_line(store[fd], i);
	store[fd] = ft_save_line(store[fd]);
	return (line);
}
