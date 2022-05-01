NAME	= libftprintf.a

CFLAGS	= -Wall -Wextra -Werror

CC		= gcc 

INC		= ./includes/ft_printf.h

SRCS	= ft_printf.c ./includes/ft_printf_utils_one.c ./includes/ft_printf_utils_two.c \
		  ./includes/ft_print_unsign_nbr.c ./includes/ft_print_ptr.c ./includes/ft_print_hex_nbr.c

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib ${NAME}
	
all: $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -rf $(OBJS) 

fclean: clean	
	-rm -rf $(NAME)
	
re:		fclean all

.PHONY: all clean fclean re
