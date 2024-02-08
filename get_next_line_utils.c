/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarimov <jkarimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:30:44 by jkarimov          #+#    #+#             */
/*   Updated: 2024/02/08 19:59:05 by jkarimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!s3)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			s3[i] = s1[i];
	while (s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[j] = '\0';
	free (s1);
	return (s3);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

// char	*ft_substr(char const *s, unsigned int start, size_t n)
// {
// 	char	*buffer;
// 	size_t	i;
// 	size_t	s_len;

// 	s_len = ft_strlen(s);
// 	if (s_len < start)
// 	{
// 		start = 0;
// 		n = 0;
// 	}
// 	if ((s_len - start) < n)
// 		n = s_len - start;
// 	buffer = (char *)malloc(sizeof(char) * n + 1);
// 	if (!buffer)
// 		return (NULL);
// 	i = 0;
// 	while (i < n)
// 	{
// 		buffer[i] = s[start + i];
// 		i++;
// 	}
// 	buffer[i] = '\0';
// 	return (buffer);
// }
