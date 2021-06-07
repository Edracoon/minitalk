NAME1 =		server

NAME2 =		client

CFLAGS =	-Wall -Wextra -Werror -g -fsanitize=address

SRCS1 =		srcs/server/main.c \

SRCS2 =		srcs/client/main.c \

OBJS1 =		$(SRCS1:.c=.o)

OBJS2 =		$(SRCS2:.c=.o)

all:		$(NAME1)

$(NAME1):	libft $(OBJS1) $(OBJS2)
			gcc $(CFLAGS) $(OBJS1) ./libft/libft.a -o $(NAME1)
			gcc $(CFLAGS) $(OBJS2) ./libft/libft.a -o $(NAME2)

libft:
			make -C ./libft

clean:
			rm -f $(OBJS1) $(OBJS2)

fclean:		clean
			rm -f $(NAME1) $(NAME2)
			make fclean -C ./libft

re: 		fclean all

.PHONY:		re clean fclean all libft