NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

#Dir of the libft

LIBFT = libft

#File .h || -L = dir of the .h file || -lft, -l to say its a lib, ft the name of the lib

HEADER = ft_printf.h -L./libft -lft

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

#make -C to call the libft
#cp to copy the libft.a to the ft_printf dir

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

#Compile with the flags

.o.c:
	@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
