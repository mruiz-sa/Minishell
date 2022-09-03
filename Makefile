# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manu <manu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 12:23:52 by mruiz-sa          #+#    #+#              #
#    Updated: 2022/09/03 20:55:54 by manu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= minishell
SRC_DIR		=	src
SRC 		= 	$(SRC_DIR)/env.c \
				$(SRC_DIR)/error.c \
				$(SRC_DIR)/ft_read.c \
				$(SRC_DIR)/get_prompt.c \
				$(SRC_DIR)/main.c \
				$(SRC_DIR)/signals.c \
				$(SRC_DIR)/state.c \

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
OBJECTS = $(SRC:.c=.o)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) -I include -I libft -o $@ $^

$(NAME): $(OBJECTS)
	@clear
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJECTS) -I include -I libft libft/libft.a -lreadline -o $(NAME)
	@echo "\n\033[92m"-------------\\n👌 COMPILED 👌\\n-------------\\n"\033[0m\n"

all: $(NAME)

clean: 
	@clear
	@echo "\n\033[31m"-------------------\\n💣 DELETED FILES 💣\\n-------------------\\n"\033[0m\n"
	@rm -f $(OBJECTS)

fclean: clean
	@make fclean -C ./libft
	@rm -rf $(NAME)
	@rm -rf minishell
	@rm -rf libft.a

re: fclean all

.PHONY: all clean re