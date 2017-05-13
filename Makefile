# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahunt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 15:41:53 by ahunt             #+#    #+#              #
#    Updated: 2016/11/30 15:41:58 by ahunt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf

CC = gcc

INC += include libft/include

LIBFT = ./libft/libft.a

LIBFT_LINK = -L libft -lft

MLX = ./minilibx_macos/libmlx.a

MLX_LINK = -L minilibx_macos -lmlx

CFLAGS += $(foreach d, $(INC), -I$d)

FRMWRK = -framework OpenGL -framework AppKit

AR = ar

RLIB = ranlib

RM = rm -rf

SRC_BASE = 	main.c \
			buffer_to_image.c \
			calc_distance.c \
			check_if_hit.c \
			clear_buffer.c \
			delta_dist.c \
			determine_line_size.c \
			determine_wall_distance.c \
			draw.c \
			draw_floor.c \
			fill_texture_buffer.c \
			floor_casting.c \
			free_memory.c \
			get_texture_x.c \
			get_wallx.c \
			hook.c \
			init_box_states.c \
			init_grid.c \
			init_map.c \
			init_mlx.c \
			init_parameters.c \
			malloc_buffer.c \
			malloc_textures.c \
			move_player.c \
			my_key_pressed.c \
			my_loop_hook.c \
			redraw_game.c \
			rotate_view.c \
			s_timer.c \
			s_timer_access.c \
			update_timer.c \
			fps.c \
			get_top_scores.c \
			draw_game_displays.c \

SRC = $(addprefix src/, $(SRC_BASE))

OBJ = $(addprefix obj/, $(SRC_BASE:.c=.o))

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(OBJ): | obj

obj:
	mkdir -p $@

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) -o $@ $^  $(CFLAGS) -L libft -lft -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

debug: $(OBJ)
	$(CC) -fsanitize=address  -o $@ $^  $(CFLAGS) -L libft -lft -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

clean:
	$(RM) $(OBJ)
	make -C ./libft clean

fdf_clean:
	$(RM) $(OBJ)

fclean: fdf_clean
	$(RM) $(NAME)
	$(RM) obj
	make -C ./libft fclean

fdf_fclean: fdf_clean
	$(RM) $(NAME)
	$(RM) obj

re: fdf_fclean all
	make -C ./libft re

.PHONY: all clean fclean re
