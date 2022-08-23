# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 12:07:06 by eel-ghan          #+#    #+#              #
#    Updated: 2022/08/23 17:18:03 by eel-ghan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g

MLX =  -lmlx -framework OpenGL -framework AppKit

FILES = cub3D.c src/get_next_line.c src/render.c \
		src/hooks.c src/img_pix_put.c src/draw_line_algo.c src/init.c\
		src/render_3D.c src/check_cub_file/check_file.c\
		src/check_cub_file/check_tex_f_c_utils.c src/check_cub_file/check_file_utils.c\
		src/check_cub_file/check_file_utils01.c src/check_cub_file/check_map.c\
		src/check_cub_file/check_map_utils.c src/hooks_utils.c src/handle_door.c\
		src/init_utils.c src/raycasting/raycasting.c src/raycasting/cal_distance.c\
		src/raycasting/raycasting_init.c src/raycasting/set_distance.c\
		src/raycasting/compare_distances.c src/render_util.c src/error.c\

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