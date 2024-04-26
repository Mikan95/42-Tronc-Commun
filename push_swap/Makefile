NAME = push_swap
CC = gcc
CCFLAGS = -Wall -Werror -Wextra
RM = rm -f
LIBFT_DIR = libft

SRC_FILES = $(addsuffix .c, push_swap push_swap_utils ft_printf ft_printf_utils ft_atol \
ft_split ft_split_utils init_stack lst_manip sort_stacks sort_stacks_utils cheapest rr_rrr \
prep_for_push)
OBJ := $(SRC_FILES:.c=.o)


all: $(NAME)

#run make in libft subdirectory, copy it to current dir and
#rename it to $(NAME), then ar it with objs of current dir
$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(NAME)
	@echo "Compilation done"

%.o : %.c
	$(CC) $(CCFLAGS) -c $< -o $@ -I $(LIBFT_DIR)

clean:
	$(RM) $(OBJ)
	@echo "Clean done"

fclean: clean
	$(RM) $(NAME)
	@echo "Fclean done"

re: fclean all

.PHONY: clean fclean re
