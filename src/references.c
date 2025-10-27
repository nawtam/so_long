/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   references.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 13:26:14 by ntamacha          #+#    #+#             */
/*   Updated: 2025/10/23 21:15:38 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	nb_colonne(char *carte)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(carte, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line[i] && line[i] != '\n' && line[i] != '\r')
		i++;
	free(line);
	clear_gnl(fd);
	close(fd);
	return (i);
}

int	nb_ligne(char *carte)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(carte, O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] != '\n' && line[0] != '\r')
			i++;
		free(line);
	}
	clear_gnl(fd);
	close(fd);
	return (i);
}
