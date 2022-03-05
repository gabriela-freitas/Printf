NAME = libftprintf.a

SRCS_ALL = ft_printf.c
# SRCS_BONUS =

OBJS_ALL =	$(SRCS_ALL:.c=.o)
# OBJS_BONUS =	$(SRCS_BONUS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

.c.o:
	$(CC) -c $(CFLAGS) $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_ALL)
	@ar rcs $(NAME) $(OBJS_ALL)

# bonus: $(OBJS_BONUS)
# 	@ar rcs $(NAME) $(OBJS_BONUS)

clean:
	@rm -f $(OBJS_ALL) $(OBJS_BONUS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
