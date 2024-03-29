/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarimov <jkarimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:30:41 by jkarimov          #+#    #+#             */
/*   Updated: 2024/02/11 22:51:26 by jkarimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char		*line;
	static char	*store;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	store = ft_read_line(fd, store);
	if (!store)
		return (free (store), NULL);
	line = ft_line(store, i);
	store = ft_save_line(store);
	return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		fd;

// 	fd = open("text.txt", O_RDONLY);

// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s\n", line);
// 		free (line);
// 	}
// 	close(fd);
// 	return (0);
// }
