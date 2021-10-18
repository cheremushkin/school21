NAME		= libft.a

LIB			:= ar rcs
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

SRC_DIR		:= ./
OBJ_DIR		:= ./

SRC_FILES	:= ft_max.c \
				ft_min.c \
				ft_atoi.c \
				ft_itoa.c \
				ft_bzero.c \
				ft_split.c \
				ft_malloc_.c \
				ft_calloc.c \
				ft_calloc_.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memset.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_strlen.c \
				ft_substr.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_memmove.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_striteri.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_strrev.c \
				ft_itoa_base.c
SRCS		:= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS		:= $(SRCS:.c=.o)

SRC_B_FILES	:= ft_lstnew.c \
				ft_lstmap.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstsize.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstadd_back.c \
				ft_lstadd_front.c
SRCS_B		:= $(addprefix $(SRC_DIR), $(SRC_B_FILES))
OBJS_B		:= $(SRCS_B:.c=.o)

RM			:= rm -rf

all: $(NAME)

bonus: all $(OBJS_B)
	$(LIB) $(NAME) $(OBJS_B)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader $(SRC_FILES) $(SRC_B_FILES)
	norminette -R CheckDefine libft.h

.PHONY: all clean fclean re norm bonus