# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 01:32:14 by rel-isma          #+#    #+#              #
#    Updated: 2023/01/26 05:19:26 by rel-isma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER_SOURCES = server.c ft_memset.c
SERVER_OBJECTS = $(SERVER_SOURCES:.c=.o)
NAME = server

SERVER_SOURCES_BONUS = server_bonus.c ft_memset.c
SERVER_OBJECTS_BONUS = $(SERVER_SOURCES_BONUS:.c=.o)
NAME_B = server_bonus

CLIENT_SOURCES = client.c ft_atoi.c
CLIENT_OBJECTS = $(CLIENT_SOURCES:.c=.o)
NAMEC = client

CLIENT_SOURCES_BONUS = client_bonus.c ft_atoi.c
CLIENT_OBJECTS_BONUS = $(CLIENT_SOURCES_BONUS:.c=.o)
NAMEC_B = client_bonus

PRINTF_PATH  = ./ft_printf
PRINTF_NAME  = ftprintf

all: printf $(NAME) $(NAMEC)

%.o: %.c Minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: printf $(NAME_B) $(NAMEC_B)

printf:
	@make -C $(PRINTF_PATH)

$(NAME): $(SERVER_OBJECTS)
	$(CC) -L$(PRINTF_PATH) -l$(PRINTF_NAME) $(SERVER_OBJECTS) -o $(NAME)
	
$(NAME_B): $(SERVER_OBJECTS_BONUS)
	$(CC) -L$(PRINTF_PATH) -l$(PRINTF_NAME) $(SERVER_OBJECTS_BONUS) -o $(NAME_B)

$(NAMEC): $(CLIENT_OBJECTS)
	$(CC) $(CLIENT_OBJECTS) -o $(NAMEC)

$(NAMEC_B): $(CLIENT_OBJECTS_BONUS)
	$(CC) $(CLIENT_OBJECTS_BONUS) -o $(NAMEC_B)

clean:
	rm -f $(SERVER_OBJECTS) $(CLIENT_OBJECTS) $(SERVER_OBJECTS_BONUS) $(CLIENT_OBJECTS_BONUS)
	@make clean -C $(PRINTF_PATH)

fclean: clean
	rm -f $(NAME) $(NAMEC) $(NAME_B) $(NAMEC_B)
	@make fclean -C $(PRINTF_PATH)

re: fclean all

