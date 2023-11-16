SRC = $(addsuffix .c, )

OBJS := $(SRC:%.c=%.o)

NAME = libftprintf.a

CC = gcc

CCFLAGS = -Wall -Werror -Wextra

INC_DIR = .

CPPFLAGS = -I$(INC_DIR)

RM = rm -f

ARNAME = ar rcs $(NAME)

all: $(NAME)

$(NAME): $(OBJS)
	$(ARNAME) $(OBJS)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
