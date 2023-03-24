# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 06:04:44 by asouchet          #+#    #+#              #
#    Updated: 2023/02/23 11:43:04 by asouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
MINILIB = minilib
CFLAGS = -Wall -Wextra -Werror -lm -D MAIN
CC = gcc
SRC_PATH = ./
OPTIONS = -I./libft -I../mlx -g3 -O3 -fsanitize=address 
SRC = main.c location.c complex.c color.c mandelbrot.c hook.c burning_ship.c
SRCS = $(addprefix $(SRC_PATH),$(SRC))
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(MINILIB):
			make -C $(MINILIB)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@ $(OPTIONS)

$(NAME): $(OBJ)
	$(CC) -L../mlx -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME) $(OPTIONS)

clean:	
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:		fclean all

.PHONY: re fclean clean all  $(NAME) $(MINILIB)
