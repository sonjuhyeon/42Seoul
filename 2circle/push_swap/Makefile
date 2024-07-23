NAME = push_swap
HEADERS = ./push_swap.h
SRCS = push_swap.c	\
	   ft_atoi.c	\
	   ft_split.c	\
	   ft_list_utils.c	\
	   ft_ps_utils.c	\
	   ft_swap.c	\
	   ft_push.c	\
	   ft_rotate.c	\
	   ft_reverse_rotate.c	\
	   ft_sort.c	\
	   ft_sort_utils.c
BONUS_SRCS = bonus.c	\
			 bonus.c	\
			 bonus.c

OBJS =  $(SRCS:.c=.o)
BONUS_OBJS =  $(BONUS_SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c
	gcc -c $(FLAGS) $< -I $(HEADERS) -o $@

$(NAME) : $(OBJS)
	gcc $(FLAGS) -o $(NAME) $(OBJS)

bonus : $(BONUS_OBJS)
	gcc $(FLAGS) -o $(NAME) $(BONUS_OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
