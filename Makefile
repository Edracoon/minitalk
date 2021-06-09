NAME1 =		server

NAME2 =		client

CFLAGS +=	-Wall -Wextra -Werror

SRCS1 =		srcs/server/server.c
SRCSB1 =	srcs/server/server_bonus.c

SRCS2 =		srcs/client/client.c srcs/client/char_to_binary.c
SRCSB2 =	srcs/client/client_bonus.c srcs/client/char_to_binary.c

OBJS1 =		$(SRCS1:.c=.o)
OBJS2 =		$(SRCS2:.c=.o)

OBJSB1 =	$(SRCSB1:.c=.o)
OBJSB2 =	$(SRCSB2:.c=.o)

all:		$(NAME1)

$(NAME1):	libft $(OBJS1) $(OBJS2)
			gcc $(CFLAGS) $(OBJS1) ./libft/libft.a -o $(NAME1)
			gcc $(CFLAGS) $(OBJS2) ./libft/libft.a -o $(NAME2)

bonus:		libft $(OBJSB1) $(OBJSB2)
			gcc $(CFLAGS) $(OBJSB1) ./libft/libft.a -o $(NAME1)
			gcc $(CFLAGS) $(OBJSB2) ./libft/libft.a -o $(NAME2)

libft:
			make -C ./libft

clean:
			rm -f $(OBJS1) $(OBJS2)
			rm -f $(OBJSB1) $(OBJSB2)
			make clean -C ./libft

fclean:		clean
			rm -f $(NAME1) $(NAME2)
			make fclean -C ./libft

re: 		fclean all

.PHONY:		re clean fclean all libft