NAME =		server

NAME2 =		client

CFLAGS +=	-Wall -Wextra -Werror

SRCS1 =		srcs/server/server.c
SRCSB1 =	srcs/server/server_bonus.c

SRCS2 =		srcs/client/client.c
SRCSB2 =	srcs/client/client_bonus.c

ifdef AVEC_BONUS
	OBJS1 =		$(SRCSB1:.c=.o)
	OBJS2 =		$(SRCSB2:.c=.o)
else
	OBJS1 =		$(SRCS1:.c=.o)
	OBJS2 =		$(SRCS2:.c=.o)
endif

all:		libft $(NAME) $(NAME2)

$(NAME):	$(OBJS1)
			gcc $(CFLAGS) $(OBJS1) ./libft/libft.a -o $(NAME)

$(NAME2):	$(OBJS2)
			gcc $(CFLAGS) $(OBJS2) ./libft/libft.a -o $(NAME2)

bonus:
			make AVEC_BONUS=1 all

libft:
			make -C ./libft

clean:
			rm -f $(OBJS1) $(OBJS2)
			rm -f $(SRCSB1:.c=.o) $(SRCSB2:.c=.o)
			make clean -C ./libft

fclean:		clean
			rm -f $(NAME) $(NAME2)
			make fclean -C ./libft

re: 		fclean all

.PHONY:		re clean fclean all libft bonus