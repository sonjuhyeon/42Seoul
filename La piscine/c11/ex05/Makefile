NAME = do-op
PATH_SRC = ./srcs
HEADERS = ./includes
SRCS = $(PATH_SRC)/ft_atoi.c $(PATH_SRC)/ft_calculator.c $(PATH_SRC)/ft_putstr.c $(PATH_SRC)/ft_putnbr.c $(PATH_SRC)/main.c
OBJS =  $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c
	gcc -c $(FLAGS) $< -I $(HEADERS) -o $@

$(NAME) : $(OBJS)
	gcc $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
