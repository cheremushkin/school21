NAME			:=	libft.a
CLEAN_GOALS		:=	clean fclean

LIB				:=	ar rcs
CC				:=	gcc
CFLAGS			:=	-Wall -Wextra -Werror
DEPFLAGS		:=	-MMD
RM				:=	rm -rf

SRCS_DIR		:=	./
HDRS_DIR		:=	./
BUILD_DIR		:=	./build/

SRCS_FILES		:=	ft_abs.c \
					ft_atoi.c \
					ft_bzero.c \
					ft_calloc.c \
					ft_calloc_.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_itoa_base.c \
					ft_list_at.c \
					ft_list_create_elem.c \
					ft_list_delete.c \
					ft_list_delete_elem.c \
					ft_list_foreach.c \
					ft_list_last.c \
					ft_list_map.c \
					ft_list_push_back.c \
					ft_list_push_front.c \
					ft_list_size.c \
					ft_malloc_.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_putchar_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_putstr_fd.c \
					ft_split.c \
					ft_strchr.c \
					ft_strdup.c \
					ft_striteri.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_strmapi.c \
					ft_strncmp.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strrev.c \
					ft_strtrim.c \
					ft_substr.c \
					ft_tolower.c \
					ft_toupper.c
HDRS_FILES		:=	libft.h \
					libft_bases.h
OBJS_FILES		:=	$(SRCS_FILES:.c=.o)
DEPS_FILES		:=	$(SRCS_FILES:.c=.d)
SRCS			:=	$(addprefix $(SRCS_DIR),$(SRCS_FILES))
HDRS			:=	$(addprefix $(HDRS_DIR),$(HDRS_FILES))
OBJS			:=	$(addprefix $(BUILD_DIR),$(OBJS_FILES))
DEPS			:=	$(addprefix $(BUILD_DIR),$(DEPS_FILES))

all: $(NAME)

$(NAME): $(OBJS)
	$(LIB) $@ $(OBJS)

$(BUILD_DIR)%.o: $(SRCS_DIR)%.c Makefile | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HDRS_DIR) $(DEPFLAGS)

ifeq ($(filter $(CLEAN_GOALS),$(MAKECMDGOALS)),)
-include $(DEPS)
endif

$(BUILD_DIR):
	mkdir $@

clean:
ifneq ($(wildcard $(BUILD_DIR)),)
	$(RM) $(BUILD_DIR)
endif

fclean: clean
ifneq ($(wildcard $(NAME)),)
	$(RM) $(NAME)
endif

re:
	$(MAKE) fclean
	$(MAKE) all

norm:
	@norminette `git ls-files`

.PHONY: all clean fclean re norm