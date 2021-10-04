NAME		:= libft.a

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

SRC_DIR		:= ./srcs/
SRC_FILES	:= ft_putchar.c \
				ft_putstr.c \
				ft_strcmp.c \
				ft_strlen.c \
				ft_swap.c

SRCS		:= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS		:= $(SRCS:.c=.o)

HEADERS		:= -I ./includes/

LIB			:= ar -rcs

RM			:= rm -rf


all: $(NAME)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY all clean fclean re