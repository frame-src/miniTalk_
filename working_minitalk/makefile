NAME_SERVER =  server
NAME_CLIENT =  client
NAME_SERVER_B =  server_bonus
NAME_CLIENT_B =  client_bonus

ODIR = obj
SDIR = src
ODIR_B = obj_bonus
SDIR_B = src_bonus

SRC_SERVER =	./src/server.c\
				./src/utils.c

SRC_CLIENT =	./src/client.c\
				./src/utils.c

SRC_SERVER_B =	./src_bonus/server_bonus.c\
				./src_bonus/utils_bonus.c

SRC_CLIENT_B=	./src_bonus/client_bonus.c\
				./src_bonus/utils_bonus.c

OBJ_SERVER =	$(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRC_SERVER))
OBJ_CLIENT =	$(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRC_CLIENT))
OBJ_SERVER_B =	$(patsubst $(SDIR_B)/%.c, $(ODIR_B)/%.o, $(SRC_SERVER_B))
OBJ_CLIENT_B =	$(patsubst $(SDIR_B)/%.c, $(ODIR_B)/%.o, $(SRC_CLIENT_B))

CC = cc
CFLAGS = -Wall -Wextra -Werror

all:	${NAME_CLIENT} ${NAME_SERVER}

$(NAME_SERVER):$(ODIR) $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)
	echo "server done;"

$(NAME_SERVER_B):$(ODIR_B) $(OBJ_SERVER_B)
	$(CC) $(CFLAGS) $(OBJ_SERVER_B) -o $(NAME_SERVER_B)
	echo "server bonus done;"

$(NAME_CLIENT):$(ODIR) $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)
	echo "client done;"

$(NAME_CLIENT_B):$(ODIR_B) $(OBJ_CLIENT_B)
	$(CC) $(CFLAGS) $(OBJ_CLIENT_B) -o $(NAME_CLIENT_B)
	echo "client done;"

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(ODIR_B)/%.o: $(SDIR_B)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

bonus: ${NAME_CLIENT_B} ${NAME_SERVER_B}

clean:
	rm -rf $(ODIR) $(ODIR_B)

fclean: clean
	rm $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_B) $(NAME_CLIENT_B)

re: fclean all

$(ODIR):
	mkdir -p $(ODIR)

$(ODIR_B):
	mkdir -p $(ODIR_B)