# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 14:05:20 by kbobrov           #+#    #+#              #
#    Updated: 2017/05/13 18:09:38 by kbobrov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = fractol.c ft_mandelbrot.c ft_image.c ft_julia.c ft_burnship.c ft_mouse_hook.c ft_kaleidoscope.c ft_newton.c ft_color.c ft_keys.c

OBJ = $(SRC:.c=.o)

HEAD = fractal.h

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc -o $(NAME) -O3 -lmlx -framework OpenGL -framework AppKit -lpthread $(OBJ) libft/*.o

%.o: %.c
	@gcc $(FLAGS) -c -o  $@ $<

cleanlib:
	@make clean -C libft/

fcleanlib:
	@make fclean -C libft/

clean: cleanlib
	@rm -f $(OBJ)

fclean:	clean fcleanlib
	@rm -f $(NAME)

re: fclean all
