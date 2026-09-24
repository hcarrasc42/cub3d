/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:58:27 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/05/31 12:24:20 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

#define BUFFER_SIZE 42

size_t	ft_strlen_get(const char *s)
{
	int	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

int	ft_strnl(const char *s)
{
	int	i;
	int	find;

	i = 0;
	if (!s || s[0] == '\0')
		return (-1);
	if ((char)s[0] == '\n')
		return (-2);
	while (s[i] && (char)s[i] != '\n')
	{
		if ((char)s[i] != '\n')
			find = 1;
		i++;
	}
	if (s[i] == '\0')
		return (-1);
	if (find == 1)
		return (++i);
	else
		return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		index;

	if (!s)
		return (0);
	if ((int)len == -2)
		len = 1;
	if ((int) start == -2)
		start = 1;
	if (start >= ft_strlen_get(s) || len <= 0)
		return (0);
	index = 0;
	if (len > ft_strlen_get(s))
		len = ft_strlen_get(s) - start;
	str = (char *)malloc((len + 1) * sizeof(*str));
	if (!str)
		return (0);
	while (s[start] && index < len)
	{
		str[index] = s[start];
		index++;
		start++;
	}
	str[index] = '\0';
	return (str);
}

char	*read_buffer(char *str, int fd, size_t *bytes_read)
{
	char	*aux;
	char	buffer[BUFFER_SIZE + 1];

	aux = ft_strjoin(str, "");
	while (*bytes_read > 0 && ft_strnl(aux) == -1)
	{
		*bytes_read = read(fd, buffer, BUFFER_SIZE);
		if ((int)*bytes_read <= 0)
		{
			if ((int)*bytes_read == 0)
				return (aux);
			free(aux);
			return (NULL);
		}
		buffer[*bytes_read] = '\0';
		if (!aux)
			aux = ft_substr(buffer, 0, BUFFER_SIZE);
		else
			aux = ft_strjoin(aux, buffer);
	}
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*aux;
	char		*line;
	size_t		bytes_read;

	bytes_read = BUFFER_SIZE;
	aux = ft_strjoin(str, "");
	str = NULL;
	if (fd == -1)
		return (NULL);
	aux = read_buffer(aux, fd, &bytes_read);
	if (!aux)
		return (NULL);
	line = ft_substr(aux, 0, ft_strnl(aux));
	str = ft_substr(aux, ft_strnl(aux), ft_strlen_get(aux));
	if (bytes_read <= 0)
		free(str);
	free(aux);
	return (line);
}
