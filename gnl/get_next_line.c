/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:34:01 by itsiros           #+#    #+#             */
/*   Updated: 2024/12/10 11:44:31 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(char *s, int c)
{
	char	*str;
	char	letter;
	size_t	i;

	i = 0;
	str = (char *)s;
	letter = c;
	while (s[i])
	{
		if (str[i] == letter)
			return (str);
		i++;
	}
	if (s[i] == '\0' && letter == '\0')
		return (str);
	return (NULL);
}


static char	*bufferline(int fd, char *leftovers, char *buffer)
{
	ssize_t	bytesread;
	char	*temp;

	bytesread = 1;
	while (bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free (leftovers);
			return (NULL);
		}
		else if (bytesread == 0)
			break ;
		buffer[bytesread] = '\0';
		if (!leftovers)
			leftovers = ft_strdup("");
		if (!leftovers)
			return (NULL);
		temp = leftovers;
		leftovers = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (leftovers);
}
static char	*dealwithnewline(char *line)
{
	char	*leftovers;
	ssize_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0 || line[i + 1] == 0)
		return (NULL);
	leftovers = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*leftovers == 0)
	{
		free (leftovers);
		leftovers = NULL;
	}
	line[i + 1] = '\0';
	return (leftovers);
}

char	*get_next_line(int fd)
{
	static char	*leftovers;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (leftovers);
		free (buffer);
		leftovers = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = bufferline(fd, leftovers, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	leftovers = dealwithnewline(line);
	return (line);
}

// #include <stdio.h>
// int main() {
// 	int fd = open("./tests/story.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("error opening file");
// 		return -1;
// 	}
// 	get_next_line(fd);
// 	get_next_line(fd);
// 	get_next_line(fd);
// 	get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	close (fd);
// 	return 0;
// }