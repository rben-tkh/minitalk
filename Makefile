NAME_SERVER	=	server
NAME_CLIENT	=	client

FLAGS		=	-Wall -Wextra -Werror

SRC_SERVER	=	src/server.c src/minitalk_utils.c
SRC_CLIENT	=	src/client.c src/minitalk_utils.c

OBJ_SERVER	=	$(SRC_SERVER:%.c=%.o)
OBJ_CLIENT	=	$(SRC_CLIENT:%.c=%.o)

%.o:			%.c
				$(CC) $(FLAGS) -c $< -o $@

all:			$(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER):	$(OBJ_SERVER)
				$(CC) $(FLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)
$(NAME_CLIENT):	$(OBJ_CLIENT)
				$(CC) $(FLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)

clean:
				rm -rf $(OBJ_SERVER) $(OBJ_CLIENT)

fclean:			clean
				rm -rf $(NAME_SERVER) $(NAME_CLIENT)

re:				fclean all

.PHONY:			all clean fclean re