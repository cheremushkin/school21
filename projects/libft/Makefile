NAME		:= libft.a

LIB			:= ar rcs
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

SRC_DIR		:= .
OBJ_DIR		:= .

SRC_FILES	:= $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES	:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

RM			:= rm -rf

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(LIB) $(NAME) $(OBJ_FILES)

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader $(SRC_FILES)
	norminette -R CheckDefine libft.h

.PHONY: all clean fclean re norm