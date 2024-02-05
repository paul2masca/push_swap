# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 14:52:11 by pde-masc          #+#    #+#              #
#    Updated: 2024/02/05 16:07:25 by pde-masc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -rf

NAME    = push_swap
HEADER  = push_swap.h

BLUE 	= \033[0;34m
GREEN 	= \033[0;32m
RED 	= \033[0;31m
RESET 	= \033[0m

SRCS    = swap.c push.c rotate.c rrotate.c stack_utils.c stack.c \
		  small_sort.c mutual_sort_utils.c mutual_sort.c push_swap.c ft.c

OBJS    = ${SRCS:.c=.o}

HEADERS	= push_swap.h

all: ${NAME}

${NAME}: $(OBJS)
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME} 

%.o:    %.c $(HEADER) Makefile
	${CC} ${CFLAGS} -c -o $@ $<

clean:
	${RM} ${OBJS} ${NAME}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
