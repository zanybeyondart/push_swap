NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRC = a_moves.c\
	ab_moves.c\
	b_moves.c\
	push_swap.c\
	setters.c\
	utilities.c\
	utilities_2.c\
	utilities_3.c\
	parsing.c\
	libft.c\
	mini_sorts.c\

OBJS = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@ $(CC) $(CFLAGS) $(OBJS)  -o $(NAME)
	
clean :
	@ $(RM) $(OBJS)

fclean : clean
	@ $(RM) $(NAME)

re : fclean all