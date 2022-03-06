NAME = libftprintf.a

SRCS_ALL = ft_printf.c
# SRCS_BONUS =

OBJS_ALL =	$(SRCS_ALL:.c=.o)
# OBJS_BONUS =	$(SRCS_BONUS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: libft $(NAME)

.c.o: $(SRCS_ALL)
	$(CC) -c $(CFLAGS) $< -o $(<:.c=.o)

libft:
	make -C libft/

extract: libft.a
	ar -xv libft.a

$(NAME): $(OBJS_ALL)
	@ar rcs $(NAME) $(OBJS_ALL) -Llibft -lft

# bonus: $(OBJS_BONUS)
# 	@ar rcs $(NAME) $(OBJS_BONUS)

clean:
	@rm -f $(OBJS_ALL)
	make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re libft
