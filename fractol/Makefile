NAME	=	fractol
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
MLX_FLAG = -lmlx -framework OpenGL -framework AppKit
RM		=	rm -f
SRCS	=	main.c \
			julia.c \
			mandelbrot.c \
			complex.c \
			my_atof.c \
			utils_error.c\
			mlx_init.c\
			hook.c\
			hook1.c\
			hook_destroy.c

OBJS	= 	$(SRCS:%.c=%.o)

LIBFT	=	libft
LIBFT_A	=	$(LIBFT)/libft.a

all:	$(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
		$(CC) $(CFLAGS) $(MLX_FLAG) $^ -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:	
		$(RM) $(OBJS) $(LIBFT)/*.o $(LIBFT_A)

fclean:	clean
		$(RM) $(NAME) 

re:		fclean all

.PHONY:	all clean fclean re