/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:34:45 by nawel             #+#    #+#             */
/*   Updated: 2025/10/24 12:10:00 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *g)
{
	int	new_y;
	int	new_x;

	new_x = g->player_x;
	new_y = g->player_y - 1;
	if (g->map[new_y][new_x] == '1')
		return ;
	if (g->map[new_y][new_x] == 'C')
		g->collected++;
	if (g->map[new_y][new_x] == 'E')
	{
		if (g->collected >= g->total_item)
			exit_game(g);
		else
			return ;
	}
	if (g->map[new_y][new_x] != '1')
	{
		g->map[g->player_y][g->player_x] = '0';
		g->map[new_y][new_x] = 'P';
		g->player_y = new_y;
		g->moves++;
		ft_printf("moves : %d\n", g->moves);
		text_map(g);
	}
}

void	move_down(t_game *g)
{
	int	new_y;
	int	new_x;

	new_x = g->player_x;
	new_y = g->player_y + 1;
	if (g->map[new_y][new_x] == '1')
		return ;
	if (g->map[new_y][new_x] == 'C')
		g->collected++;
	if (g->map[new_y][new_x] == 'E')
	{
		if (g->collected >= g->total_item)
			exit_game(g);
		else
			return ;
	}
	if (g->map[new_y][new_x] != '1')
	{
		g->map[g->player_y][g->player_x] = '0';
		g->map[new_y][new_x] = 'P';
		g->player_y = new_y;
		g->moves++;
		ft_printf("moves : %d\n", g->moves);
		text_map(g);
	}
}

void	move_left(t_game *g)
{
	int	new_y;
	int	new_x;

	new_x = g->player_x - 1;
	new_y = g->player_y;
	if (g->map[new_y][new_x] == '1')
		return ;
	if (g->map[new_y][new_x] == 'C')
		g->collected++;
	if (g->map[new_y][new_x] == 'E')
	{
		if (g->collected >= g->total_item)
			exit_game(g);
		else
			return ;
	}
	if (g->map[new_y][new_x] != '1')
	{
		g->map[g->player_y][g->player_x] = '0';
		g->map[new_y][new_x] = 'P';
		g->player_x = new_x;
		g->moves++;
		ft_printf("moves : %d\n", g->moves);
		text_map(g);
	}
}

void	move_right(t_game *g)
{
	int	new_y;
	int	new_x;

	new_x = g->player_x + 1;
	new_y = g->player_y;
	if (g->map[new_y][new_x] == '1')
		return ;
	if (g->map[new_y][new_x] == 'C')
		g->collected++;
	if (g->map[new_y][new_x] == 'E')
	{
		if (g->collected >= g->total_item)
			exit_game(g);
		else
			return ;
	}
	if (g->map[new_y][new_x] != '1')
	{
		g->map[g->player_y][g->player_x] = '0';
		g->map[new_y][new_x] = 'P';
		g->player_x = new_x;
		g->moves++;
		ft_printf("moves : %d\n", g->moves);
		text_map(g);
	}
}

int	key_press(int key, t_game *g)
{
	if (key == KEY_ESC)
		exit_game(g);
	if (key == KEY_W)
		move_up(g);
	if (key == KEY_S)
		move_down(g);
	if (key == KEY_A)
		move_left(g);
	if (key == KEY_D)
		move_right(g);
	return (0);
}
