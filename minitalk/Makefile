CLIENT = client
SERVER = server
CC = gcc
CCFLAGS = -Wall -Werror -Wextra
RM = rm -f
FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

SRV_FILES = $(addsuffix .c, server)
SRV_OBJ := $(SRV_FILES:.c=.o)

CLIENT_FILES = $(addsuffix .c, client)
CLIENT_OBJ := $(CLIENT_FILES:.c=.o)

all: $(SERVER) $(CLIENT)

#compiles server object files
$(SERVER): $(SRV_OBJ) $(FT_PRINTF_LIB)
	$(CC) $(CCFLAGS) $(SRV_OBJ) -o $(SERVER) $(FT_PRINTF_LIB)
	@echo "Server compilation done"

#compiles client object files
$(CLIENT): $(CLIENT_OBJ) $(FT_PRINTF_LIB)
	$(CC) $(CCFLAGS) $(CLIENT_OBJ) -o $(CLIENT) $(FT_PRINTF_LIB)
	@echo "Client compilation done"

%.o : %.c
	$(CC) $(CCFLAGS) -c $< -o $@ -I $(FT_PRINTF_DIR)

$(FT_PRINTF_LIB):
	make -C $(FT_PRINTF_DIR)

clean:
	$(RM) $(SRV_OBJ) $(CLIENT_OBJ)
	@echo "Clean done"

fclean: clean
	$(RM) $(SERVER) $(CLIENT)
	@echo "Fclean done"

re: fclean all
