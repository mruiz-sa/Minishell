# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manu <manu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 12:23:52 by mruiz-sa          #+#    #+#              #
#    Updated: 2022/09/20 19:28:03 by manu             ###   ########.fr        #
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
SRC 		= 	$(SRC_DIR)/array.c \
				$(SRC_DIR)/command.c \
				$(SRC_DIR)/command_table.c \
				$(SRC_DIR)/env.c \
				$(SRC_DIR)/error.c \
				$(SRC_DIR)/exec_cmd.c \
				$(SRC_DIR)/ft_lexer.c \
				$(SRC_DIR)/ft_read.c \
				$(SRC_DIR)/ft_strcpy_until.c \
				$(SRC_DIR)/get_prompt.c \
				$(SRC_DIR)/malloc.c \
				$(SRC_DIR)/signals.c \
				$(SRC_DIR)/state.c \
				$(SRC_DIR)/str.c \
				$(SRC_DIR)/token.c \

MAIN_SRCS	= 	$(SRC_DIR)/main.c $(SRC)
TEST_SRCS	= 	$(SRC_DIR)/tests.c \
				$(SRC_DIR)/tests_token.c \
				$(SRC_DIR)/tests_command_table.c \
				$(SRC)

CC 			= gcc
BREW_DIR 	= /Users/${USER}/.brew/opt
# BREW_DIR 	= /usr/local/opt
INCLUDES	= -I include -I libft -I${BREW_DIR}/readline/include
CFLAGS 		= -Wall -Werror -Wextra $(INCLUDES) -g3
OBJECTS		= 	$(MAIN_SRCS:.c=.o)
TESTS_OBJS	= 	$(TEST_SRCS:.c=.o)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) -o $@ $^

$(NAME): $(OBJECTS)
	@clear
	@make bonus -C libft
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) libft/libft.a -lreadline -L${BREW_DIR}/readline/lib -o $(NAME)
	@echo "\n\033[92m"-------------\\n👌 COMPILED 👌\\n-------------\\n"\033[0m\n"

all: $(NAME)

test: $(TESTS_OBJS)
	@clear
	@make bonus -C libft
	@$(CC) $(CFLAGS) $(INCLUDES) $(TESTS_OBJS) libft/libft.a -lreadline -L${BREW_DIR}/readline/lib -o run_test_$(NAME)
	@echo "\n\033[92m"-------------\\n👌 TESTS COMPILED 👌\\n-------------\\n"\033[0m\n"
	@echo
	@echo Running tests ...
	@./run_test_$(NAME)

clean:
	@clear
	@echo "\n\033[31m"-------------------\\n💣 DELETED FILES 💣\\n-------------------\\n"\033[0m\n"
	@rm -f $(OBJECTS) $(TESTS_OBJS)

fclean: clean
	@make fclean -C ./libft
	@rm -rf $(NAME)
	@rm -rf run_test_$(NAME)
	@rm -rf minishell
	@rm -rf libft.a

re: fclean all

.PHONY: all clean re test
