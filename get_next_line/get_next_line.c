/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayo-ca <amayo-ca@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:19:40 by amayo-ca          #+#    #+#             */
/*   Updated: 2022/04/13 16:07:33 by amayo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *buff)
{
	int		x;
	char	*str;

	x = 0;
	if (buff[x] == '\0')
		return (NULL);
	while (buff[x] != '\0' && buff[x] != '\n')
		x++;
	str = (char *) malloc(sizeof(char) * (x + 2));
	if (!str)
		return (NULL);
	x = 0;
	while (buff[x] != '\0' && buff[x] != '\n')
	{
		str[x] = buff[x];
		x++;
	}
	if (buff[x] == '\n')
	{
		str[x] = buff[x];
		x++;
	}
	str[x] = '\0';
	return (str);
}

char	*ft_storage(char *storage)
{
	int		x;
	int		c;
	char	*str;

	x = 0;
	while (storage[x] != '\0' && storage[x] != '\n')
		x++;
	if (!storage[x])
	{
		free(storage);
		return (NULL);
	}
	str = (char *) malloc(sizeof(char) * (ft_strlen(storage) - x + 1));
	if (!str)
		return (NULL);
	x++;
	c = 0;
	while (storage[x])
		str[c++] = storage[x++];
	str[c] = '\0';
	free(storage);
	return (str);
}

char	*storage(int fd, char *storage)
{
	char	*buff;
	int		bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(storage, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		storage = ft_strjoin(storage, buff);
	}
	free(buff);
	return (storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = storage(fd, str);
	if (!str)
		return (NULL);
	line = get_line(str);
	str = ft_storage(str);
	return (line);
}
