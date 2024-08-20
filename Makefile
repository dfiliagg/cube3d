# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 10:46:16 by dfiliagg          #+#    #+#              #
#    Updated: 2023/05/30 10:27:42 by adi-fort         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d
FLAGS	=  -Wall -Wextra -Werror
CC		= gcc ${FLAGS}
RM		= rm -f
SRC		= $(wildcard *.c) $(wildcard get_next_line/*.c) $(wildcard init/*.c) $(wildcard draw/*.c) $(wildcard raycaster/*.c) $(wildcard moves/*.c) $(wildcard parser/*.c)
OBJ		= ${SRC:.c=.o}
LFT		= libft/libft.a
MLB		= minilibx-linux/libmlx.a
MLX		= -L ./minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz

all: ${NAME}

${LFT}:
		make -C libft
${MLB}:
		make -C minilibx-linux
.o:.c
	${CC} ${OBJ} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ} ${LFT} ${MLB}
	${CC} ${OBJ} ${LFT} ${MLB} $(MLX) -o ${NAME}

clean:
	${RM} ${OBJ}
	make clean -C libft
	make clean -C minilibx-linux

fclean: clean
	${RM} ${NAME}
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re