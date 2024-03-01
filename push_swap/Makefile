NAME = push_swap
CC = gcc
CCFLAGS = -Wall -Werror -Wextra
RM = rm -f
SRC_FILES = $(addsuffix .c, push_swap push_swap_utils ft_printf ft_printf_utils ft_atoi)
OBJS := $(SRC_FILES:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
