# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 01:32:14 by rel-isma          #+#    #+#              #
#    Updated: 2023/01/25 04:12:33 by rel-isma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SERVER_SOURCES = server.c ft_memset.c
SERVER_OBJECTS = $(SERVER_SOURCES:.c=.o)
NAME = server

CLIENT_SOURCES = client.c ft_atoi.c
CLIENT_OBJECTS = $(CLIENT_SOURCES:.c=.o)
NAMEC = client
PRINTF_PATH  = ft_printf/libftprintf.a

all: printf $(NAME) $(NAMEC)

$(NAME): $(SERVER_OBJECTS)
	$(CC) $(CFLAGS) ${PRINTF_PATH} $(SERVER_OBJECTS) -o $(NAME)

printf:
	cd ft_printf && make

$(NAMEC): $(CLIENT_OBJECTS)
	$(CC) $(CFLAGS) $(CLIENT_OBJECTS) -o $(NAMEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SERVER_OBJECTS) $(CLIENT_OBJECTS)
	cd ft_printf && make clean

fclean: clean
	rm -f $(NAME) $(NAMEC)
	cd ft_printf && make fclean

re: fclean all

