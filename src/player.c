/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:07:52 by nawel             #+#    #+#             */
/*   Updated: 2025/10/21 17:33:45 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pos_player(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == 'P')
			{
				g->player_x = x;
				g->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
