# Detect the operating system
UNAME_S := $(shell uname -s)

#define default project name, compiler, compiler flags and others for Linux
ifeq ($(UNAME_S), Linux)
NAME = play
CC = gcc
CCFLAGS = -Wall -Werror -Wextra -Ilib/minilibx-linux/ -Ilib/ft_printf/ -Ilib/get_next_line/
LDFLAGS = -Llib -lmlx -lftprintf -lgnl -lXext -lX11
RM = rm -f

#define source files
SRC_FILES = $(addsuffix .c, init error_checks map_utils)
#define object files
OBJ := $(SRC_FILES:.c=.o)

#define library targets
MLX = lib/libmlx.a
FTPRINTF = lib/libftprintf.a
GNL = lib/libgnl.a

#default rules
all: $(NAME)

#build minilibx, ft_printf and GNL
$(MLX):
	$(MAKE) -C ./lib/minilibx-linux/
$(FTPRINTF):
	$(MAKE) -C ./lib/ft_printf/ -f Makefile
$(GNL):
	$(MAKE) -C ./lib/get_next_line/ -f Makefile

#compile the object files
%.o : %.c
	$(CC) $(CCFLAGS) -Ilib -c $< -o $@

#compile the project
$(NAME): $(OBJ) $(MLX) $(FTPRINTF) $(GNL)
	$(CC) $(CCFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)
	@echo "Compilation done"

#clean the object files
clean:
	$(RM) $(OBJ)
	@make clean -C ./lib/minilibx-linux/
	@make clean -C ./lib/ft_printf/
	@make clean -C ./lib/get_next_line/
	@echo "Clean done"

#clean the object files and the project
fclean: clean
		$(RM) $(NAME) $(MLX) $(FTPRINTF) $(GNL)
		@echo "Fclean done"

#recompile the project
re: fclean all


.PHONY: clean fclean re
endif

#check if the operating system is MacOS and change variables accordingly
ifeq ($(UNAME_S), Darwin)
NAME = play
CC = gcc -v
CCFLAGS = -Wall -Werror -Wextra -I./lib/minilibx_macos/ -I./lib/ft_printf/ -I./lib/get_next_line/
LDFLAGS = -L./lib -lmlx -lftprintf -lgnl -framework OpenGL -framework AppKit
MLX = ./lib/libmlx.a
FTPRINTF = ./lib/libftprintf.a
GNL = ./lib/libgnl.a

#define source files
SRC_FILES = $(addsuffix .c, init error_checks map_utils)
#define object files
OBJ := $(SRC_FILES:.c=.o)

#default rules
all: $(NAME)

#build minilibx, ft_printf and GNL
$(MLX):
	make -C ./lib/minilibx_macos/ -f Makefile
$(FTPRINTF):
	make -C ./lib/ft_printf/ -f Makefile
$(GNL):
	make -C ./lib/get_next_line/ -f Makefile

#compile the object files
%.o : %.c
	$(CC) $(CCFLAGS) -Ilib -c $< -o $@

#compile the project
$(NAME): $(OBJ) $(MLX) $(FTPRINTF) $(GNL)
	$(CC) $(CCFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)
	@echo "Compilation done"

#clean the object files
clean:
	$(RM) $(OBJ)
	@make clean -C ./lib/minilibx_macos/
	@make clean -C ./lib/ft_printf/
	@make clean -C ./lib/get_next_line/
	@echo "Clean done"

#clean the object files and the project
fclean: clean
	$(RM) $(NAME)
	$(RM) $(MLX)
	@make fclean -C ./lib/ft_printf/
	@make fclean -C ./lib/get_next_line/
	@echo "Fclean done"

#recompile the project
re: fclean all

sanitize: CCFLAGS += -fsanitize=address -g3
sanitize: re

.PHONY: clean fclean re
endif

