/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 22:26:40 by ntamacha          #+#    #+#             */
/*   Updated: 2025/10/17 22:26:40 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	text_case(t_game *g, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_wall, x * g->case_size, y * g->case_size);
	else if (c == '0')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_floor, x * g->case_size, y * g->case_size);
	else if (c == 'C')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_item, x * g->case_size, y * g->case_size);
	else if (c == 'P')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_player, x * g->case_size, y * g->case_size);
	else if (c == 'E')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_exit, x * g->case_size, y * g->case_size);
}

void	text_line(t_game *g, int y)
{
	int	x;

	x = 0;
	while (g->map[y][x])
	{
		text_case(g, g->map[y][x], x, y);
		x++;
	}
}

void	text_map(t_game *g)
{
	int	y;

	y = 0;
	while (g->map[y])
	{
		text_line(g, y);
		y++;
	}
}

void	pack_textures(t_game *g)
{
	int	s;

	s = g->case_size;
	g->img_wall = mlx_xpm_file_to_image(g->mlx, "img/wall.xpm", &s, &s);
	g->img_floor = mlx_xpm_file_to_image(g->mlx, "img/floor.xpm", &s, &s);
	g->img_player = mlx_xpm_file_to_image(g->mlx, "img/player.xpm", &s, &s);
	g->img_item = mlx_xpm_file_to_image(g->mlx, "img/item.xpm", &s, &s);
	g->img_exit = mlx_xpm_file_to_image(g->mlx, "img/exit.xpm", &s, &s);
	g->textures = 1;
	if (!g->img_wall || !g->img_floor || !g->img_player
		|| !g->img_item || !g->img_exit)
	{
		write(2, "Error : chargement texture\n", 27);
		exit_game(g);
	}
}
