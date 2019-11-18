
SRCS	= ft_printf.c ft_flag_tools.c ft_parsing.c ft_putaddress.c ft_putall.c

SRCS	+= ft_putc.c ft_puthex.c ft_putint.c ft_puts.c ft_putuint.c ft_var_tools.c

LIBFT	= libft/libft.a

OBJS	= $(SRCS:.c=.o)

NAME	= ft_printf.a

LIBFT	= libft/libft.a

GCC		= gcc

FLAGS	= -Wall -Wextra -Werror

INCLUDEH	= -I ft_printf.h



all:	$(NAME)

.PHONY:	clean fclean re bonus bench bclean

$(NAME): $(OBJS)
	cd libft && $(MAKE)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(B_OBJS)
	cd libft && $(MAKE) clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	cd libft && $(MAKE) fclean

re: fclean all

%.o: %.c
	$(GCC) $(FLAGS) $(INCLUDEH) -c $<  -o $(<:.c=.o)

