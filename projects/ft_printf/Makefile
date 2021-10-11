NAME		:= libftprintf.a
NAME_EX		:= bin

LIB			:= ar rcs
CC			:= gcc
CFLAGS		:= -Wall

HEADERS_DIR	:= ./headers
SRC_DIR		:= ./sources
OBJ_DIR		:= ./objectives

MAIN		:= $(SRC_DIR)/main.c
SRCS		:= $(filter-out $(SRC_DIR)/main.c,$(wildcard $(SRC_DIR)/*.c))
OBJS		:= $(subst $(SRC_DIR),$(OBJ_DIR),$(SRCS:.c=.o))
HEADERS		:= $(wildcard $(HEADERS_DIR)/*.h)

LIBFT_DIR	:= ./libft
LIBFT_NAME	:= -lft
LIBFT		:= $(addprefix $(LIBFT_DIR),$(LIBFT_NAME))
LIBFT_OBJS	:= $(LIBFT_DIR)/*.o
LIBFT_MAKE	:= $(MAKE) -C $(LIBFT_DIR)

RM			:= rm -rf

all: $(NAME)

debug: CFLAGS += -g
debug: all

$(NAME): libmake $(OBJS) $(HEADERS)
	$(LIB) $(NAME) $(OBJS) $(LIBFT_OBJS)

$(NAME_EX): libmake $(MAIN) $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(NAME_EX) $(MAIN) $(OBJS) -I $(HEADERS_DIR) -I $(LIBFT_DIR) -L $(LIBFT_DIR) $(LIBFT_NAME)

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

srcs:
	@echo $(SRCS)

norm:
	norminette -R CheckForbiddenSourceHeader $(SRCS)
	norminette -R CheckDefine libft.h

.PHONY: all clean fclean re norm bonus