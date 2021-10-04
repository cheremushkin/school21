NAME		:= bsq

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

SRC_DIR		:= ./sources/
SRC_FILES	:= ft_bsq.c \
				ft_dp.c \
				ft_is.c \
				ft_legend.c \
				ft_params.c \
				ft_parse_map.c \
				ft_puts.c \
				ft_solve_map.c \
				ft_string.c \
				ft_string2.c \
				ft_utils.c

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
