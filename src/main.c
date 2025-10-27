/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:00:00 by ntamacha          #+#    #+#             */
/*   Updated: 2025/10/10 15:00:00 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *mlx)
{
	free(mlx);
	exit(0);
	return (0);
}

int	get_case_size(char *carte)
{
	int	max_w;
	int	max_h;
	int	cols;
	int	rows;
	int	size;

	max_w = 1920;
	max_h = 1080;
	cols = nb_colonne(carte);
	rows = nb_ligne(carte);
	size = 64;
	while ((cols * size > max_w) || (rows * size > max_h))
	{
		size--;
		if (size < 64)
			return (0);
	}
	return (size);
}

int	init_game(t_game *g, char *carte)
{
	int	width;
	int	height;

	g->moves = 0;
	g->collected = 0;
	g->textures = 0;
	g->mlx = mlx_init();
	if (!g->mlx)
		return (write(2, "Error : initialisation mlx\n", 27), exit_game(g), 0);
	g->map = create_map(carte, g);
	if (!g->map)
		return (write(2, "Error : creation de map\n", 24), exit_game(g), 0);
	g->case_size = get_case_size(carte);
	if (g->case_size == 0)
		return (ft_printf("Error : map trop grande\n"), exit_game(g), 0);
	width = nb_colonne(carte) * g->case_size;
	height = nb_ligne(carte) * g->case_size;
	g->win = mlx_new_window(g->mlx, width, height, "So_Long");
	if (!g->win)
		return (ft_printf("Error : creation fenetre\n"), exit_game(g), 0);
	return (1);
}

void	start_game(t_game *g)
{
	pack_textures(g);
	pos_player(g);
	text_map(g);
	mlx_key_hook(g->win, key_press, g);
	mlx_hook(g->win, 17, 0, exit_game, g);
	mlx_loop(g->mlx);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		write(2, "Error : le nombre d'arguments n'est pas correct\n", 48);
		return (1);
	}
	if (!parsing(av[1]))
		return (1);
	if (!init_game(&game, av[1]))
		return (1);
	start_game(&game);
	return (0);
}
