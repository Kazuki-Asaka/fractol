NAME	=	libft.a
AR		=	ar crs
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
SRCS	=	ft_strlen.c \
			ft_strncmp.c \
			ft_putendl_fd.c
OBJS	= 	$(SRCS:%.c=%.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:	
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME) 

bonus:	$(NAME)

re:		fclean all

.PHONY:	all clean fclean re