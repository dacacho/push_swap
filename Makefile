# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danierod <danierod@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 16:26:20 by danierod          #+#    #+#              #
#    Updated: 2023/01/04 16:26:19 by danierod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_PATH = ./

CC = cc

RM = rm -rf

SOURCES = $(wildcard ./*.c)

OBJECTS = $(SOURCES:.c=.o)

%.o:		%.c
			$(CC) -c $^ -o $@

all: $(NAME)
	
%.o: %.c
	@$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJECTS)
	-@$(CC) $(OBJECTS) -o $(NAME)
	
clean:
	@$(RM) $(OBJECTS)

fclean:	clean
	@$(RM) $(NAME)

re: fclean all
	clear

.PHONY: all clean fclean re