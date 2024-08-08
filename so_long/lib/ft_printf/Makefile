NAME = ../libftprintf.a
CC = gcc
CCFLAGS = -Wall -Wextra -Werror -I./libft
RM = rm -f


SRC_FILES = $(addprefix ft_, $(addsuffix .c, printf conversion char str putptr \
putint putnbr_hex putnbr_dec))

LIBFT_SRC_FILES = $(addprefix libft/ft_, $(addsuffix .c, atoi bzero calloc isalnum isalpha isascii \
isdigit isprint memchr memcmp memcpy memmove memset strchr strdup strlcat strlcpy \
strlen strncmp strnstr strrchr substr tolower toupper strjoin strtrim split itoa \
strmapi striteri putchar_fd putstr_fd putendl_fd putnbr_fd))

OBJ = $(SRC_FILES:.c=.o) $(LIBFT_SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	@echo "Compilation done"

%.o : %.c
	$(CC) $(CCFLAGS) -Ilibft -c $< -o $@

libft/%.o : libft/%.c
	$(CC) $(CCFLAGS) -Ilibft -c $< -o $@

clean:
	$(RM) $(OBJ)
	@make clean -C ./libft
	@echo "Clean done"

fclean: clean
	$(RM) $(NAME)
	@make fclean -C ./libft
	@echo "Fclean done"

re: fclean all

.PHONY: clean fclean re
