# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 20:11:52 by yadereve          #+#    #+#              #
#    Updated: 2024/04/17 23:51:18 by yadereve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
COMPRESS = ar rcs
RM = rm -rf

SRC_DIR = sources
SRC = $(wildcard $(SRC_DIR)/*.c)
LIBFT = libft/libft.a
OBJ_DIR = objects
OBJ = $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))

#bonus
SRC_BONUS_DIR = sources_bonus
FILES_BONUS = $(wildcard $(SRC_BONUS_DIR)/*.c)
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

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(BLUE)       __"
	@echo ".-----|__.-----.-----.--.--."
	@echo "|  _  |  |  _  |  -__|_   _|"
	@echo "|   __|__|   __|_____|__.__|"
	@echo "|__|     |__|$(RESET)"
	@echo "\n"
	@echo "created: $(GREEN)$(NAME)$(RESET)"
#	@echo "---- Exemple run: ./pipex infile "ls -l" "wc -l" outfile

bonus: $(NAME)_bonus

$(NAME)_bonus: $(OBJ_BONUS_DIR) $(OBJ_BONUS) all
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME)_bonus
	@echo "$(GREEN)\t $(NAME)_bonus$(RESET)\n"

$(LIBFT):
	@$(MAKE) -C ./libft --no-print-directory

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS_DIR):
	@mkdir -p $@

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

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

re: fclean all

.PHONY: all clean fclean re
