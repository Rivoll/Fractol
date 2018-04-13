NAME = fractol
CC = gcc
SRC = main.c\
	  ft_event.c\
	  ft_mandelbrot.c\
	  ft_julia.c\
	  ft_douady.c\
	  ft_fractal.c\
	  ft_siegel.c

SALE = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Werror -Wextra 

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) libft/libft.a 
	$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit libft/libft.a $(SALE) 

libft/libft.a :
	make -C libft

clean :
	make -C libft/ clean
	@rm -f $(OBJ)

fclean : clean
	make -C libft/ fclean
	@rm -f $(NAME)

re : fclean all

%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $< 

.PHONY : all clean fclean 