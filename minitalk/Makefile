CC = gcc
CCFLAGS = -Wall -Werror -Wextra
RM = rm -f


SRV_FILES = $(addsuffix .c, server)
SRV_BONUS_FILES = $(addsuffix .c, server_bonus)
CLIENT_FILES = $(addsuffix .c, client)
CLIENT_BONUS_FILES = $(addsuffix .c, client_bonus)
SRV_OBJ := $(SRV_FILES:.c=.o)
SRV_BONUS_OBJ := $(SRV_BONUS_FILES:.c=.o)
CLIENT_OBJ := $(CLIENT_FILES:.c=.o)
CLIENT_BONUS_OBJ := $(CLIENT_BONUS_FILES:.c=.o)
SERVER = server
SERVER_BONUS = server_bonus
CLIENT = client
CLIENT_BONUS = client_bonus

FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

all: $(SERVER) $(CLIENT)

#compiles server object files
$(SERVER): $(SRV_OBJ) $(FT_PRINTF_LIB)
	$(CC) $(CCFLAGS) -o $@ $(SRV_OBJ) -L$(FT_PRINTF_DIR) -lftprintf
	@echo "Server compilation done"

#compiles client object files
$(CLIENT): $(CLIENT_OBJ) $(FT_PRINTF_LIB)
	$(CC) $(CCFLAGS) -o $@ $(CLIENT_OBJ) -L$(FT_PRINTF_DIR) -lftprintf
	@echo "Client compilation done"

#compiles bonus server object files
$(SERVER_BONUS): $(SRV_BONUS_OBJ) $(FT_PRINTF_LIB)
	$(CC) $(CCFLAGS) -o $@ $(SRV_BONUS_OBJ) -L$(FT_PRINTF_DIR) -lftprintf
	@echo "Server bonus compilation done"

#compiles bonus client object files
$(CLIENT_BONUS): $(CLIENT_BONUS_OBJ) $(FT_PRINTF_LIB)
	$(CC) $(CCFLAGS) -o $@ $(CLIENT_BONUS_OBJ) -L$(FT_PRINTF_DIR) -lftprintf
	@echo "Client bonus compilation done"

$(FT_PRINTF_LIB):
	make -C $(FT_PRINTF_DIR)

%.o : %.c
	$(CC) $(CCFLAGS) -c $< -o $@ -I $(FT_PRINTF_DIR)

clean:
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(RM) $(SRV_OBJ) $(CLIENT_OBJ) $(SRV_BONUS_OBJ) $(CLIENT_BONUS_OBJ)
	@echo "Clean done"

fclean: clean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	@echo "Fclean done"

re: fclean all

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

.PHONY: all clean fclean re bonus
