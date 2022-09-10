# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 12:23:52 by mruiz-sa          #+#    #+#              #
#    Updated: 2022/09/10 15:16:15 by manugarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# brew install readline
# brew info readline
# brew --prefix readline
# brew link --force readline
# For compilers to find readline you may need to set:
#   export LDFLAGS="-L/usr/local/opt/readline/lib"
#   export CPPFLAGS="-I/usr/local/opt/readline/include"
# -lreadline -L/usr/local/opt/readline/lib -I/usr/local/opt/readline/include

NAME 		= minishell
SRC_DIR		=	src
SRC 		= 	$(SRC_DIR)/env.c \
				$(SRC_DIR)/error.c \
				$(SRC_DIR)/ft_lexer.c \
				$(SRC_DIR)/ft_read.c \
				$(SRC_DIR)/get_prompt.c \
				$(SRC_DIR)/main.c \
				$(SRC_DIR)/malloc.c \
				$(SRC_DIR)/signals.c \
				$(SRC_DIR)/state.c \

CC = gcc
INCLUDES = -I include -I libft -I/Users/${USER}/.brew/opt/readline/include
CFLAGS = -Wall -Werror -Wextra $(INCLUDES) -g3
OBJECTS = $(SRC:.c=.o)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) -o $@ $^

$(NAME): $(OBJECTS)
	@clear
	@make -C libft
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) libft/libft.a -lreadline -L/Users/${USER}/.brew/opt/readline/lib -o $(NAME)
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
