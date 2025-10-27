/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_caractere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:09:38 by ntamacha          #+#    #+#             */
/*   Updated: 2025/10/19 16:09:38 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_all(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n' && map[y][x] != '\r')
		{
			if (map[y][x] != 'P' && map[y][x] != 'C' && map[y][x] != 'E' &&
			map[y][x] != '0' && map[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	count_char(char **map, char c)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	check_cara(char **map, t_game *g)
{
	int	p;
	int	e;
	int	c;

	(void)*g;
	if (!check_all(map))
	{
		write(2, "Error : caractere non conforme\n", 31);
		return (0);
	}
	p = count_char(map, 'P');
	if (p != 1)
		write(2, "Error : la carte doit contenir un 'P'\n", 38);
	e = count_char(map, 'E');
	if (e != 1)
		write(2, "Error : la carte doit contenir un 'E'\n", 38);
	c = count_char(map, 'C');
	if (c < 1)
		write(2, "Error : la carte doit contenir au moins un 'C'\n", 47);
	if (p != 1 || e != 1 || c < 1)
		return (0);
	return (1);
}
