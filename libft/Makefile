NAME = libft.a
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g
OBJ_DIR = objects

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strtrim.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_split.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c \
		ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		ft_printf.c ft_putchar.c ft_putuncig.c ft_putstr.c ft_putnbr.c\
		ft_strlen.c ft_puthex.c ft_putpoint.c get_next_line.c\

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME) $(OBJ_DIR)

re:	fclean all

.PHONY: all clean fclean re
