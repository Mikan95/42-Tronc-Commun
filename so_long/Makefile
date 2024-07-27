#define project name, compiler, compiler flags and others
NAME = play
CC = gcc
CCFLAGS = -Wall -Werror -Wextra -Iminilibx-linux/
LDFLAGS = -Lminilibx-linux/ -lmlx -lXext -lX11
RM = rm -f

#define source files
SRC_FILES = $(addsuffix .c, init)
#define object files
OBJ := $(SRC_FILES:.c=.o)

#default rules
all: $(NAME)

#compile the project
$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)
	@echo "Compilation done"

#compile the object files
%.o : %.c
	$(CC) $(CCFLAGS) -c $< -o $@

#clean the object files
clean:
	$(RM) $(OBJ)
	@echo "Clean done"

#clean the object files and the project
fclean: clean
	$(RM) $(NAME)
	@echo "Fclean done"

#recompile the project
re: fclean all

.PHONY: clean fclean re
