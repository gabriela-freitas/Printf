NAME = libft.a

SRCS_ALL =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_memchr.c ft_memcpy.c ft_memcmp.c ft_memmove.c \
ft_memset.c ft_strchr.c ft_strdup.c ft_strjoin.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
ft_tolower.c ft_toupper.c ft_putchar_fd.c ft_strtrim.c \
ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

SRCS_BONUS =	ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c \

OBJS_ALL =	$(SRCS_ALL:.c=.o)
OBJS_BONUS =	$(SRCS_BONUS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

.c.o:
	$(CC) -c $(CFLAGS) $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_ALL)
	@ar rcs $(NAME) $(OBJS_ALL)
	# @mkdir -p obj
	# @mv $(OBJS_ALL) obj

bonus: $(OBJS_BONUS)
	@ar rcs $(NAME) $(OBJS_BONUS)

clean:
	@rm -f $(OBJS_ALL) $(OBJS_BONUS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
