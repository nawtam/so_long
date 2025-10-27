/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:05:48 by ntamacha          #+#    #+#             */
/*   Updated: 2025/10/10 15:05:48 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 5)
		return (0);
	if (ft_strncmp(str + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

int	line_len(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n' && line[i] != '\r')
		i++;
	return (i);
}

int	check_rectangle(char *carte)
{
	int		fd;
	char	*line;
	int		ref;
	int		len;

	fd = open(carte, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line && *line == '\n')
		line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	ref = line_len(line);
	while (line)
	{
		len = line_len(line);
		if (len && len != ref)
			return (free(line), clear_gnl(fd), close(fd), 0);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	check_walls(char **map)
{
	int	x;
	int	y;
	int	len;

	y = 0;
	len = line_len(map[0]);
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n' && map[y][x] != '\r')
		{
			if ((y == 0 || !map[y + 1]) && map[y][x] != '1')
				return (ft_printf("Error : carte pas entouré par des murs\n"),
					0);
			if ((x == 0 || x == len - 1) && map[y][x] != '1')
				return (ft_printf("Error : carte pas entouré par des murs\n"),
					0);
			x++;
		}
		y++;
	}
	return (1);
}

int	parsing(char *carte)
{
	char	**map;
	t_game	tmp;

	if (!check_ber(carte))
		return (write(2, "Error : nom du fichier sans ber\n", 32), 0);
	if (!check_format(carte))
		return (write(2, "Error : la carte n'est pas conforme\n", 36), 0);
	if (!check_rectangle(carte))
		return (write(2, "Error : la carte n'est pas conforme\n", 36), 0);
	map = create_map(carte, &tmp);
	if (!map)
		return (write(2, "Error : map non crée (parsing)\n", 31), 0);
	if (!check_walls(map))
		return (free_map(map), 0);
	if (!check_cara(map, &tmp))
		return (free_map(map), 0);
	if (!check_res(map))
		return (write(2, "Error : la carte doit etre résolvable\n", 38),
			free_map(map), 0);
	free_map(map);
	return (1);
}
