# SRC = ./push_swap.c ./setters.c

# OBJ = $(SRC:.c=.o)

# all : ${OBJ}
# 	@ar -rcs lib.a ${OBJ}
# 	cc push_swap.c lib.a

all :
	cc push_swap.c setters.c utilities.c b_moves.c a_moves.c utilities_2.c utilities_3.c -fsanitize=address

p1 :
	cc push_swap.c setters.c utilities.c b_moves.c a_moves.c utilities_2.c utilities_3.c -o 99 -fsanitize=address

clean :
	rm -f ./99 ./p1 ./a.out