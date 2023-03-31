# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 03:57:27 by jode-vri          #+#    #+#              #
#    Updated: 2022/12/12 12:55:28 by jode-vri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 42sh
SRCS		= ./srcs/
INCS		= ./incs/
LIBFT_INC	= ./libft/

CC			= cc
CFLAGS		= -Wall -Wextra -Werror $(INCLUDES) -g
LIBS		= -L ./libft/ -lft -ltermcap

INCLUDES	= -I $(INCS) -I $(LIBFT_INC)

SRC			=	main.c						\
				env/env.c					\
				env/utils.c					\
				term.c						\
				run.c

OBJS		= $(addprefix $(SRCS), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(OBJS) -o $(NAME) $(LIBS)

clean:
	# make -C ./libft clean
	rm -f $(OBJS)
.PHONY: clean

fclean: clean
	# make -C ./libft fclean
	rm -f $(NAME)
.PHONY: fclean


re: fclean all
.PHONY: re
