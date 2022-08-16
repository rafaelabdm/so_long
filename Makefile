# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabustam <rabustam@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 16:56:11 by rabustam          #+#    #+#              #
#    Updated: 2022/08/16 16:10:15 by rabustam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Werror -Wextra
CC		= cc $(CFLAGS)
MLX		= -lmlx -lXext -lX11

NAME =	so_long
LIBFT =	libft/libft.a
SRCS =	ft_check_error.c ft_check_map.c ft_draw_map.c ft_handle_event.c ft_handle_images.c \
		ft_handle_map.c ft_handle_trap.c ft_player_moves.c ft_trap_moves.c main.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	cd libft && $(MAKE)

%.o: %.c
	$(CC) -c $^

clean:
	rm -f $(OBJ)

fclean: clean
	cd libft && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re