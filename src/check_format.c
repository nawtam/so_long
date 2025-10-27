/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:15:12 by ntamacha          #+#    #+#             */
/*   Updated: 2025/10/23 19:15:12 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '\n' && line[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}

int	check_format(char *carte)
{
	int		fd;
	char	*line;
	int		empty_found;

	fd = open(carte, O_RDONLY);
	if (fd < 0)
		return (0);
	empty_found = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (is_line_empty(line))
			empty_found = 1;
		else if (empty_found)
			return (free(line), clear_gnl(fd), close(fd), 0);
		free(line);
		line = get_next_line(fd);
	}
	clear_gnl(fd);
	close(fd);
	return (1);
}
