# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 06:04:44 by asouchet          #+#    #+#              #
#    Updated: 2023/01/07 20:02:38 by asouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LIBFT = libft
MINILIB = minilib
CFLAGS = -Wall -Wextra -Werror -lm -D MAIN
CC = gcc
SRC_PATH = ./
OPTIONS = -I./libft -I./mlx -g3 -O2 -fsanitize=address 
SRC = main.c location.c complex.c color.c mandelbrot.c hook.c julia.c
SRCS = $(addprefix $(SRC_PATH),$(SRC))
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
			make -C $(LIBFT)
			mv ./libft/libft.a libft.a
			ar rcs libft.a ${OBJS} 

$(MINILIB):
			make -C $(MINILIB)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@ $(OPTIONS)

$(NAME): $(OBJ)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME) $(OPTIONS)

unit: 	$(OBJ) $(LIBFT)
	$(CC) $(OBJ) -DUNIT -D UNIT -fsanitize=address -I./libft  -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit -o unit
clean:	
		rm -f $(OBJ)
		make -C $(LIBFT) clean

fclean:	clean
		rm -f $(NAME)
		make -C $(LIBFT) fclean

re:		fclean all

.PHONY: re fclean clean all $(LIBFT) $(NAME) $(MINILIB)