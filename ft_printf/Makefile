NAME = libftprintf.a
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT_DIR = libft

SRC_FILES = $(addprefix ft_, $(addsuffix .c, printf conversion))

OBJ = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@cp ${LIBFT_DIR}/libft.a .
	@mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)
	@echo "Compilation done"

%.o : %.c
	$(CC) $(CCFLAGS) -c $< -o $@ -I $(LIBFT_DIR)

clean:
	$(RM) $(OBJ)
	@make clean -C ${LIBFT_DIR}
	@echo "Clean done"

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_DIR)/libft.a
	@echo "Fclean done"

re: fclean all

.PHONY: clean fclean re
