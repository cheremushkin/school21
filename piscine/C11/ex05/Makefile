NAME		:=  do-op

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

SRC_DIR		:= ./srcs/
SRC_FILES	:= ft_atoi.c \
				ft_do_op.c \
				ft_is.c \
				ft_ops.c \
				ft_puts.c \
				ft_string.c \

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
