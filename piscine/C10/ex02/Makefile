NAME		:= ft_tail

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

SRC_DIR		:= ./srcs/
SRC_FILES	:= ft_atoi.c \
				ft_print_error.c \
				ft_files.c \
				ft_puts.c \
				ft_puts2.c \
				ft_tail.c \
				ft_string.c \
				ft_string2.c \
				ft_offset.c

SRC_MAIN	:= $(SRC_DIR)main.c
SRCS		:= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS		:= $(SRCS:.c=.o)

HEADERS		:= ./includes/

RM			:= rm -rf

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRC_MAIN) -o $(NAME) $(OBJS) -I $(HEADERS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader $(SRCS)
	norminette -R CheckForbiddenSourceHeader $(SRC_MAIN)
	norminette -R CheckDefine $(HEADERS)*

.PHONY: all clean fclean re norm
