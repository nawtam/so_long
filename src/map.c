/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:23:09 by ntamacha          #+#    #+#             */
/*   Updated: 2025/10/17 12:23:09 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_map(char *carte, t_game *g)
{
	int		fd;
	int		i;
	int		lines;
	char	**map;

	lines = nb_ligne(carte);
	fd = open(carte, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < lines)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			return (free_map(map), NULL);
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = '\0';
		i++;
	}
	map[i] = NULL;
	g->total_item = count_char(map, 'C');
	return (clear_gnl(fd), close(fd), map);
}
