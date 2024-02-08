/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarimov <jkarimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:30:41 by jkarimov          #+#    #+#             */
/*   Updated: 2024/02/08 19:58:26 by jkarimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char	*ft_read_line(int fd, char *str)
{
	char	*buffer;
	int		re;
	char	*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	re = 1;
	while (!ft_strchr(str, '\n') && re != 0)
	{
		re = read(fd, buffer, BUFFER_SIZE);
		if (re == -1)
			return (free(buffer), free(str), NULL);
		buffer[re] = '\0';
		temp = ft_strjoin(str, buffer);
		free(str);
		str = temp;
	}
	return (free(buffer), str);
}

char	*ft_line(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	s = (char *)malloc(i + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_new_line(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), NULL);
	s = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!s)
		return (free(str), NULL);
	i++;
	j = 0;
	while (str[i])
		s[j++] = str[i++];
	s[j] = '\0';
	return (free (str), s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*store;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	store = ft_read_line(fd, store);
	if (!store)
		return (NULL);
	line = ft_line(store);
	store = ft_new_line(store);
	return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		fd;

// 	fd = open("/Users/jkarimov/test/test.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("line: %s", line);
// 	free (line);
// 	close(fd);
// }
