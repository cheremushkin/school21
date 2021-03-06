NAME		:= libftprintf.a

LIB			:= ar rcs
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

SRCS_DIR	:= ./sources/
HDRS_DIR	:= ./headers/
OBJS_DIR	:= ./objectives/

SRCS_FILES	:= ft_conv.c \
				ft_eval_hex.c \
				ft_eval_number.c \
				ft_eval_string.c \
				ft_parsers.c \
				ft_strs_join.c \
				ft_eval_char.c \
				ft_eval_int.c \
				ft_eval_percent.c \
				ft_handler.c \
				ft_printf.c

HDRS_FILES	:= ft_conv.h \
				ft_eval_hex.h \
				ft_eval_number.h \
				ft_eval_string.h \
				ft_parsers.h \
				ft_strs_join.h \
				ft_eval_char.h \
				ft_eval_int.h \
				ft_eval_percent.h \
				ft_handler.h \
				ft_printf.h

OBJS_FILES	:= $(SRCS_FILES:.c=.o)

SRCS		:= $(addprefix $(SRCS_DIR),$(SRCS_FILES))
HDRS		:= $(addprefix $(HDRS_DIR),$(HDRS_FILES))
OBJS		:= $(addprefix $(OBJS_DIR),$(OBJS_FILES))

LIBFT_DIR	:= ./libft/
LIBFT_NAME	:= libft.a
LIBFT_OBJS	:= $(LIBFT_DIR)*.o
LIBFT		:= $(addprefix $(LIBFT_DIR),$(LIBFT_NAME))

RM			:= rm -rf

all: $(NAME)

bonus: all
bonus_one: all
bonus_two: all

$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS) $(LIBFT_OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HDRS) Makefile | $(OBJS_DIR) subsystem
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HDRS_DIR) -I $(LIBFT_DIR)

subsystem:
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

norm:
	@norminette `git ls-files`

.PHONY: all subsystem bonus bonus_one bonus_two clean fclean re norm