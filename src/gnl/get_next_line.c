/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:39:39 by ntamacha          #+#    #+#             */
/*   Updated: 2025/10/22 16:49:13 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_nl(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*free_all(char *buf, char *stash)
{
	free(buf);
	free(stash);
	return (NULL);
}

static char	*read_and_join(int fd, char *stash)
{
	char	*buf;
	char	*tmp;
	int		bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(stash), NULL);
	bytes = 1;
	while (!found_nl(stash) && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (free_all(buf, stash), NULL);
		buf[bytes] = '\0';
		tmp = ft_strjoin(stash, buf);
		if (!tmp)
			return (free_all(buf, stash), NULL);
		free(stash);
		stash = tmp;
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*tmp;
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_join(fd, stash);
	if (!stash || !*stash)
		return (free(stash), stash = NULL, NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = ft_substr(stash, 0, len);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	tmp = ft_substr(stash, len, ft_strlen(stash) - len);
	free(stash);
	if (!tmp)
		return (free(line), stash = NULL, NULL);
	stash = tmp;
	return (line);
}

// #include <fcntl.h>
// #include <unistd.h>
// #include <stdio.h>
// int main()
// {
// 	int	fd = open("text.txt", O_RDONLY);
// 	char *line;

// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free (line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free (line);
// 	// while (1)
// 	// {
// 	// 	line = get_next_line(fd);
// 	// 	if (!line)
// 	// 		break ;
// 	// 	printf("%s", line);
// 	// 	free (line);
// 	// }
// 	close(fd);
// 	return (0);
// }