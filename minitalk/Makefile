CLIENT = client
SERVER = server
CC = gcc
CCFLAGS = -Wall -Werror -Wextra
RM = rm -f
FT_PRINTF_DIR = ft_printf

SRV_FILES = $(addsuffix .c, server)
SRV_OBJ := $(SRV_FILES:.c=.o)

CLIENT_FILES = $(addsuffix .c, client)
CLIENT_OBJ := $(CLIENT_FILES:.c=.o)


all: $(SERVER) $(CLIENT)

#compiles server object files
$(SERVER): $(SRV_OBJ)
	$(CC) $(CCFLAGS) $(SRV_OBJ) -o $(SERVER)
	@echo "Server compilation done"

#compiles client object files
$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(CCFLAGS) $(CLIENT_OBJ) -o $(CLIENT)
	@echo "Server compilation done"

%.o : %.c
	$(CC) $(CCFLAGS) -c $< -o $@ -I $(FT_PRINTF_DIR)

clean:
	$(RM) $(SRV_OBJ)
	@echo "Clean done"

fclean: clean
	$(RM) $(SERVER)
	@echo "Fclean done"

re: fclean all

.PHONY: clean fclean re
