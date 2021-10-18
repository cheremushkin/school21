NAME		= bin
LIB_NAME	= libftprintf.a

LIB			= ar rcs
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

HEADERS_DIR	= ./headers
SRC_DIR		= ./sources
OBJ_DIR		= ./objectives

MAIN		= $(SRC_DIR)/main.c
SRCS		= $(filter-out $(SRC_DIR)/main.c, $(wildcard $(SRC_DIR)/*.c))
OBJS		= $(subst $(SRC_DIR),$(OBJ_DIR),$(SRCS:.c=.o))
HEADERS		= $(wildcard $(HEADERS_DIR)/*.h)

LIBFT_DIR	= ./libft
LIBFT_NAME	= -lft
LIBFT		= $(addprefix $(LIBFT_DIR),$(LIBFT_NAME))
LIBFT_OBJS	= $(LIBFT_DIR)/*.o
LIBFT_MAKE	= $(MAKE) -C $(LIBFT_DIR)

RM			= rm -rf

all: $(NAME)
lib: $(LIB_NAME)
bonus: lib

# debug: CFLAGS += -g
debug: all

$(NAME): libmake $(MAIN) $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN) $(OBJS) -I $(HEADERS_DIR) -I $(LIBFT_DIR) -L $(LIBFT_DIR) $(LIBFT_NAME)

$(LIB_NAME): libmake $(OBJS) $(HEADERS)
	$(LIB) $(LIB_NAME) $(OBJS) $(LIBFT_OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS_DIR) -I $(LIBFT_DIR)

libmake:
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) fclean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all ex clean fclean re libmake bonus