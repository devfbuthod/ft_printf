NAME = libftprintf.a

SRC =	include/ft_printf.c				\
		include/conv_p.c				\
		include/conv_c.c				\
		include/conv_d.c				\
		include/conv_d.c				\
		include/conv_pourcent.c			\
		include/conv_s.c				\
		include/conv_u.c				\
		include/conv_x.c				\
		include/conv_x_maj.c			\
		include/det_flag_conv_algo.c	\
		include/flags.c					\
		include/ft_printf.c				\
		include/ft_utils0.c				\
		include/ft_utils1.c				\
		include/ft_utils2.c				\
		include/ft_utils3.c				\
		include/ft_utils4.c				\
		include/ft_utils5.c				\
		include/ft_utils6.c						

O_FILES =	${SRC:.c=.o}

CC =		gcc

FLAGS =		-Wall -Wextra -Werror

INCLUDE =	include/ft_printf.h

$(NAME) :	$(O_FILES) $(INCLUDE)
			ar rcs $(NAME) $(O_FILES)

%.o :		%.c $(INCLUDE)
			$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME) $(INCLUDE)

clean:
			rm -f $(O_FILES)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all

bonus: