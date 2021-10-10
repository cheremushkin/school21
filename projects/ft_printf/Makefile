NAME		:= bin

LIB			:= ar rcs
CC			:= gcc
CFLAGS		:= -Wall

HEADERS_DIR	:= ./headers
SRC_DIR		:= ./sources
OBJ_DIR		:= ./objectives

MAIN		:= $(SRC_DIR)/main.c
SRCS		:= $(filter-out $(SRC_DIR)/main.c, $(wildcard $(SRC_DIR)/*.c))
OBJS		:= $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))
HEADERS		:= $(wildcard $(HEADERS_DIR)/*.h)

RM			:= rm -rf

all: $(NAME)

debug: CFLAGS += -g
debug: all

$(NAME): $(MAIN) $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN) $(OBJS) -I $(HEADERS_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS_DIR)

clean:
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