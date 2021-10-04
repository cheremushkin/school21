NAME		:= ft_display_file

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

SRC_DIR		:= ./srcs/
SRC_FILES	:= ft_print_file.c \
				ft_print_error.c

SRC_MAIN	:= $(SRC_DIR)main.c
SRCS		:= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS		:= $(SRCS:.c=.o)

HEADERS		:= ./includes/

LIB_BUILDER	:= ar rcs
LIB			:= $(SRC_DIR)libft.a

RM			:= rm -rf

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS)

all: obj $(NAME)

obj: $(SRCS)

$(LIB): $(OBJS)
	$(LIB_BUILDER) $(LIB) $(OBJS)

$(NAME): $(LIB)
	$(CC) $(CFLAGS) $(SRC_MAIN) -o $(NAME) $< -I $(HEADERS)

clean:
	$(RM) $(OBJS)
	$(RM) $(LIB)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader $(SRCS)
	norminette -R CheckForbiddenSourceHeader $(SRC_MAIN)
	norminette -R CheckDefine $(HEADERS)*

.PHONY: all obj clean fclean re norm
