NAME = pipex
HEADER = ./pipex.h
BONUS_HEADER = ./pipex_bonus.h
SRCS = pipex.c	\
	   ft_split.c	\
	   pipex_utils.c
BONUS_SRCS = pipex_bonus.c	\
			 ft_split_bonus.c	\
			 pipex_utils_bonus.c

OBJS =  $(SRCS:.c=.o)
BONUS_OBJS =  $(BONUS_SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c
	gcc -c $(FLAGS) $< -I $(HEADER) -o $@

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
