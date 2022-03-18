CC=cc
NAME=push_swap
BN=checker
SRC=main.c error.c sort_stack/sort_stack.c utils/utils.c utils/utils2.c utils/utils3.c utils/algo.c utils/algo2.c utils/algo3.c utils/utils4.c utils/utils5.c utils/utils6.c utils/utils7.c stack/stack.c instructions/instructions.c instructions/instructions2.c instructions/instructions3.c
LIBFT=libft/libft.a
FLAGS=-c $< -o $@
CFLAGS=-Wall -Wextra -Werror
OBJ=$(SRC:.c=.o)
SRCB=checker.c error.c sort_stack/sort_stack.c utils/utils.c utils/utils2.c utils/utils3.c utils/algo.c utils/algo2.c utils/algo3.c utils/utils4.c utils/utils5.c utils/utils6.c utils/utils7.c stack/stack.c instructions/instructions.c instructions/instructions2.c instructions/instructions3.c checker_files/checker_ins.c checker_files/get_next_line_utils.c checker_files/get_next_line.c
OBJB=$(SRCB:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(FLAGS)
$(NAME): $(OBJ)
	cd libft && make bonus
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

all: $(NAME)

$(BN): $(OBJB)
	cd libft && make bonus
	$(CC) $(SRCB) $(LIBFT) -o $(BN)

bonus: $(BN)

clean:
	cd libft && make clean
	rm -rf $(OBJ)
	rm -rf $(OBJB)
fclean:clean
	cd libft && make fclean 
	rm -f $(NAME)
	rm -f $(BN)
re:fclean $(NAME)
