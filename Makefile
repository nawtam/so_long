# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/22 20:01:32 by ntamacha          #+#    #+#              #
#    Updated: 2025/09/22 20:01:32 by ntamacha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

MLX_DIR		= minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx.a
HEADERS		= -I$(MLX_DIR) -I. -Isrc/gnl -Isrc/ft_printf

SRC =	src/main.c src/map.c src/moves.c src/player.c src/textures.c \
		src/parsing.c src/check_caractere.c src/check_res.c src/exit.c \
		src/references.c src/ft_printf/ft_putpointer.c src/ft_strncmp.c \
		src/gnl/get_next_line.c src/gnl/get_next_line_utils.c \
		src/ft_printf/ft_printf.c src/ft_printf/ft_putchar.c src/check_format.c \
		src/ft_printf/ft_putnbr.c src/ft_printf/ft_putstr.c src/ft_printf/ft_putnbr_base.c

OBJ = $(SRC:.c=.o)


all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -o $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	@make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re