# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/14 02:31:26 by cfeijoo           #+#    #+#              #
#    Updated: 2014/01/26 01:05:41 by cfeijoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = player

INCLUDEFOLDERS = -I./includes/ -I./libft/includes
LIBFOLDERS = -L./libft/
LIBS = -lft

CC = cc
CFLAGS = -Wall -Wextra -Werror

CFILES =	player.c			\
			get_board_loop.c	\
			stuff.c				\
			get_next_line.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME) :
	$(CC) -c $(CFILES) $(INCLUDEFOLDERS) $(CFLAGS)
	$(CC) $(OFILES) $(INCLUDEFOLDERS) $(LIBFOLDERS) $(LIBS) $(CFLAGS) -o $(NAME)

complibs :
	make -C libft re

updatelibs :
	cd libft && git pull
	$(MAKE) complibs

clean :
	rm -f $(OFILES)

fclean : clean
	rm -f $(NAME)

re : fclean all
