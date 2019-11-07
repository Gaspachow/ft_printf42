
SRCS	= ft_printf.c

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

