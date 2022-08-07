# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 12:07:06 by eel-ghan          #+#    #+#              #
#    Updated: 2022/08/02 17:39:13 by eel-ghan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g

MLX =  -lmlx -framework OpenGL -framework AppKit

FILES = cub3D.c src/check_map.c src/get_next_line.c src/render.c \
		src/hooks.c src/img_pix_put.c src/draw_line_algo.c src/init.c\
		src/raycasting.c src/render_walls.c\

LIBFT = src/libft/libft.a

RM = @rm -f

all :$(NAME)

$(NAME):
		@make -C src/libft && make bonus -C src/libft
		$(CC) $(CFLAGS) $(MLX) $(LIBFT) $(FILES) -o $(NAME) 
		@make clean -C src/libft
		@echo "CUB3D CREATED"
clean :
		@make clean -C src/libft

fclean : clean
		@make fclean -C src/libft
		$(RM) $(NAME)
		@echo "CUB3D DELETED"

re : fclean all