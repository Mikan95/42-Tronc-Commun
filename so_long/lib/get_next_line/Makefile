#define default target & flags
NAME = ../libgnl.a
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
RM = rm -f

#set source files
SRC_FILES = $(addsuffix .c, get_next_line get_next_line_utils)

#set object files
OBJ = $(SRC_FILES:.c=.o)

#default target
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	@echo "Compilation done"

#compile object files
%.o : %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	@echo "GNL clean done"

fclean: clean
	$(RM) $(NAME)
	@echo "GNL Fclean done"

re: fclean all

.PHONY: clean fclean re
