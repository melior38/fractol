# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asouchet <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/16 19:13:44 by asouchet          #+#    #+#              #
#    Updated: 2022/10/26 16:18:11 by asouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libft.a

SRCS	:= ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_strchr.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strrchr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memset.c \
	ft_strdup.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strnstr.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_free.c \
	ft_new_buffer_start.c \
	ft_get_lines.c \
	ft_read_till_sep.c \
	ft_gnljoin.c \
	get_next_line_bonus.c \
	get_next_line.c
B_SRCS	:= ft_lstnew.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c 

OBJS	:= $(SRCS:.c=.o)
B_OBJS	:= $(B_SRCS:.c=.o)
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror

RM		:= rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) 
	ar rc $(NAME) $(OBJS) 

bonus: $(B_OBJS)
	ar rc $(NAME) $(B_OBJS)

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all test clean fclean re
