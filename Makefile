# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 20:11:52 by yadereve          #+#    #+#              #
#    Updated: 2024/04/10 17:56:59 by yadereve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
COMPRESS = ar rcs
RM = rm -rf

SRC_DIR = sources
FILES = $(wildcard *.c)
SRC = $(addprefix $(SRC_DIR)/,$(FILES))
LIBFT = libft/libft.a
OBJ_DIR = objects
OBJ = $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))

#bonus
SRC_BONUS_DIR = sources_bonus
FILES_BONUS = check_map_bonus.c error_bonus.c initialization_bonus.c \
	load_textures_bonus.c load_textures2_bonus.c mlx_start_bonus.c \
	read_input_bonus.c so_long_bonus.c utilites_bonus.c validate_map_bonus.c \
	finish_game_bonus.c animate_bonus.c create_img_bonus.c
SRC_BONUS = $(addprefix $(SRC_BONUS_DIR)/,$(FILES_BONUS))
LIBFT = libft/libft.a
OBJ_BONUS_DIR = objects_bonus
OBJ_BONUS = $(addprefix $(OBJ_BONUS_DIR)/,$(notdir $(SRC_BONUS:.c=.o)))

#colors
GREEN = \033[1;32m
RED = \033[1;31m
BLUE = \033[1;34m
ORANGE = \033[0;33m
RESET = \033[0;0m

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_INC = -I$(MLX_DIR) -I$(MLX_DIR)/linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\n pipex \n"
	@echo "created: $(GREEN)$(NAME)$(RESET)"
#	@echo "---- Exemple run: ./pipex infile "ls -l" "wc -l" outfile

bonus: $(NAME)_bonus

$(NAME)_bonus: $(OBJ_BONUS_DIR) $(OBJ_BONUS) all
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME)_bonus
	@echo "$(GREEN)\t $(NAME)_bonus$(RESET)\n"

$(LIBFT):
	@$(MAKE) -C ./libft --no-print-directory

$(MLX_LIB):
	@$(MAKE) -C ./$(MLX_DIR) --no-print-directory

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

$(OBJ_BONUS_DIR):
	@mkdir -p $@

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@$(MAKE) -C ./libft clean --no-print-directory
	@echo "remove:\t$(RED)$(OBJ_DIR)$(RESET)"
#	@echo "\t$(RED)$(OBJ_BONUS_DIR)$(RESET)"

fclean: clean
	@$(RM) $(NAME) $(NAME)_bonus
	@$(MAKE) -C ./libft fclean --no-print-directory
	@echo "\t$(RED)"libft.a"$(RESET)"
	@echo "\t$(RED)$(NAME)$(RESET)"
#	@echo "\t$(RED)$(NAME)_bonus$(RESET)"

re: fclean all bonus

.PHONY: all clean fclean re bonus
