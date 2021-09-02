SERVER = server
CLIENT = client

OBJS_S = $(FILES_S:.c=.o)
OBJS_C = $(FILES_C:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FILES_S = server.c \
		  ft_utils.c

FILES_C = client.c \
		  ft_utils.c
		  
.PHONY : all clean fclean re

all : $(SERVER) $(CLIENT)

$(SERVER) $(CLIENT) : $(OBJS_S) $(OBJS_C)
	$(CC) $(CFLAGS) $(OBJS_S) -o $(SERVER)
	$(CC) $(CFLAGS) $(OBJS_C) -o $(CLIENT)

clean :
	rm -f *.o

fclean : clean
	rm -f $(SERVER) $(CLIENT)

re : fclean all