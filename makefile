# SRC = ./push_swap.c ./setters.c

# OBJ = $(SRC:.c=.o)

# all : ${OBJ}
# 	@ar -rcs lib.a ${OBJ}
# 	cc push_swap.c lib.a

all :
	cc push_swap.c setters.c utilities.c b_moves.c -fsanitize=address