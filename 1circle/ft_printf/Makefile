NAME = libftprintf.a
PATH_SRCS = ./srcs
PATH_BONUS_SRCS = ./bonus_srcs
HEADERS = ./includes
SRCS = $(PATH_SRCS)/ft_printf.c	\
	   $(PATH_SRCS)/ft_init.c	\
	   $(PATH_SRCS)/print_percent.c	\
	   $(PATH_SRCS)/print_char.c	\
	   $(PATH_SRCS)/print_str.c	\
	   $(PATH_SRCS)/print_unsigned_int.c	\
	   $(PATH_SRCS)/print_hexa.c	\
	   $(PATH_SRCS)/print_int.c	\
	   $(PATH_SRCS)/print_int_utils.c	\
	   $(PATH_SRCS)/print_pointer.c	\
	   $(PATH_SRCS)/utils.c
BONUS_SRCS = $(PATH_BONUS_SRCS)/ft_printf_bonus.c	\
			 $(PATH_BONUS_SRCS)/ft_init_bonus.c	\
			 $(PATH_BONUS_SRCS)/print_percent_bonus.c	\
			 $(PATH_BONUS_SRCS)/print_char_bonus.c	\
			 $(PATH_BONUS_SRCS)/print_str_bonus.c	\
			 $(PATH_BONUS_SRCS)/print_unsigned_int_bonus.c	\
			 $(PATH_BONUS_SRCS)/print_hexa_bonus.c	\
			 $(PATH_BONUS_SRCS)/print_int_bonus.c	\
			 $(PATH_BONUS_SRCS)/print_int_utils_bonus.c	\
			 $(PATH_BONUS_SRCS)/print_pointer_bonus.c	\
			 $(PATH_BONUS_SRCS)/utils_bonus.c
OBJS =  $(SRCS:.c=.o)
BONUS_OBJS =  $(BONUS_SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c
	gcc -c $(FLAGS) $< -I $(HEADERS) -o $@

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus : $(OBJS) $(BONUS_OBJS)
	ar rc $(NAME) $^

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
