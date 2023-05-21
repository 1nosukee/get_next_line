# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfaouzi <wfaouzi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 01:42:01 by wfaouzi           #+#    #+#              #
#    Updated: 2023/05/13 18:17:36 by wfaouzi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

SRCS = get_next_line.c get_next_line_utils.c

HEADER = get_next_line.h

CC = gcc

# CFLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

all: ${NAME}


${NAME}:
	${CC} -c ${SRCS} -I ${HEADER}
	
clean:
	rm -rf ${OBJS}

fclean: clean

re: fclean all