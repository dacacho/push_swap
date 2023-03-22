# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danierod <danierod@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 16:26:20 by danierod          #+#    #+#              #
#    Updated: 2023/03/22 14:20:04 by danierod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_PATH = ./

CC = cc

RM = rm -rf

SOURCES = ./utils.c ./s_oper.c ./push_swap.c ./p_oper.c ./algorithm.c ./rr_oper.c ./r_oper.c

OBJECTS = $(SOURCES:.c=.o)

%.o:		%.c
			$(CC) -c $^ -o $@

all: $(NAME)
	
%.o: %.c
	@$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJECTS)
	-@$(CC) $(OBJECTS) -o $(NAME)
	
clean:
	$(RM) $(OBJECTS)
	clear

fclean:	clean
	@$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re