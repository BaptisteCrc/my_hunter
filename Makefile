NAME	= my_hunter

CC	= gcc -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

RM	= rm -f

SRCS	=	main.c	\
		window.c	\
		init.c	\
		animation.c	\
		score.c	\
		conv.c	\
		my_putchar.c	\
		my_putstr.c	\

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) ##-lc_graph_prog

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
