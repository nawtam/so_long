/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:03:04 by ntamacha          #+#    #+#             */
/*   Updated: 2025/10/19 19:03:04 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_path(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == 'F' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = '1';
		return ;	
	}
	map[y][x] = 'F';
	flood_fill(map, y - 1, x);
	flood_fill(map, y, x - 1);
	flood_fill(map, y + 1, x);
	flood_fill(map, y, x + 1);
}

int	check_res(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				break ;
			x++;
		}
		if (map[y][x] == 'P')
			break ;
		y++;
	}
	flood_fill(map, y, x);
	if (!valid_path(map))
		return (0);
	return (1);
}
