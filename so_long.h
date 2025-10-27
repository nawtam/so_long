/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:32:13 by ntamacha          #+#    #+#             */
/*   Updated: 2025/10/21 17:32:13 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line.h"
# include "ft_printf.h"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		player_x;
	int		player_y;
	int		moves;
	int		collected;
	int		total_item;
	int		case_size;
	int		textures;

	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_item;
	void	*img_exit;
}	t_game;

//parsing
int		parsing(char *carte);
int		check_ber(char *str);
int		check_rectangle(char *carte);
int		check_walls(char **map);
int		check_all(char **map);
int		count_char(char **map, char c);
int		check_cara(char **map, t_game *g);
void	flood_fill(char **map, int y, int x);
int		valid_path(char **map);
int		check_res(char **map);
int		is_line_empty(char *line);
int		check_format(char *carte);

//map
char	**create_map(char *carte, t_game *g);
void	free_map(char **map);
int		nb_colonne(char *carte);
int		nb_ligne(char *carte);

//moves
void	move_up(t_game *g);
void	move_down(t_game *g);
void	move_left(t_game *g);
void	move_right(t_game *g);
int		key_press(int key, t_game *g);

//textures
void	pack_textures(t_game *g);
void	text_case(t_game *g, char c, int x, int y);
void	text_line(t_game *g, int y);
void	text_map(t_game *g);

int		exit_game(t_game *g);
void	clear_gnl(int fd);
void	pos_player(t_game *g);
int		nb_colonne(char *carte);
int		nb_ligne(char *carte);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
int		line_len(char *line);
int		get_case_size(char *carte);

#endif