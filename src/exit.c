/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:42:25 by nawel             #+#    #+#             */
/*   Updated: 2025/10/22 18:18:51 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	clear_gnl(int fd)
{
	char	*tmp;

	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		free(tmp);
	}
}

void	free_g_mlx(t_game *g)
{
	mlx_destroy_display(g->mlx);
	free(g->mlx);
}

int	exit_game(t_game *g)
{
	if (!g->mlx)
		exit(0);
	if (g->textures == 1)
	{
		if (g->img_wall)
			mlx_destroy_image(g->mlx, g->img_wall);
		if (g->img_floor)
			mlx_destroy_image(g->mlx, g->img_floor);
		if (g->img_player)
			mlx_destroy_image(g->mlx, g->img_player);
		if (g->img_item)
			mlx_destroy_image(g->mlx, g->img_item);
		if (g->img_exit)
			mlx_destroy_image(g->mlx, g->img_exit);
		if (g->win)
			mlx_destroy_window(g->mlx, g->win);
	}
	if (g->map)
		free_map(g->map);
	if (g->mlx)
		free_g_mlx(g);
	exit(0);
	return (0);
}
