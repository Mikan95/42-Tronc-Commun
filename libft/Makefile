SRC = $(addprefix ft_, $(addsuffix .c, atoi bzero calloc isalnum isalpha isascii \
isdigit isprint memchr memcmp memcpy memmove memset strchr strdup strlcat strlcpy \
strlen strncmp strnstr strrchr substr tolower toupper strjoin strtrim split itoa \
strmapi striteri putchar_fd putstr_fd putendl_fd putnbr_fd))

OBJS := $(SRC:%.c=%.o)

BONUS_SRC = $(addprefix bonus/, $(addsuffix _bonus.c, ft_lstnew ft_lstadd_front \
ft_lstsize ft_lstlast ft_lstadd_back))

BONUS_OBJS := $(BONUS_SRC:%.c=%.o)

NAME = libft.a

CC = gcc

CCFLAGS = -Wall -Werror -Wextra

INC_DIR = .

CPPFLAGS = -I$(INC_DIR)

RM = rm -f

ARNAME = ar rcs $(NAME)

OBJS_MANBO = $(OBJS) $(BONUS_OBJS)

all: $(NAME)

$(NAME): $(OBJS)
	$(ARNAME) $(OBJS)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	$(RM) $(OBJS_MANBO)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJS_MANBO)
	$(ARNAME) $(OBJS_MANBO)
