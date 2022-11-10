# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 12:23:52 by mruiz-sa          #+#    #+#              #
#    Updated: 2022/11/10 20:27:10 by manugarc         ###   ########.fr        #
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
				$(SRC_DIR)/array_display.c \
				$(SRC_DIR)/builtins.c \
				$(SRC_DIR)/builtins_cd.c \
				$(SRC_DIR)/builtins_echo.c \
				$(SRC_DIR)/builtins_env.c \
				$(SRC_DIR)/builtins_exit.c \
				$(SRC_DIR)/builtins_export.c \
				$(SRC_DIR)/builtins_pwd.c \
				$(SRC_DIR)/builtins_unset.c \
				$(SRC_DIR)/command.c \
				$(SRC_DIR)/command_add.c \
				$(SRC_DIR)/command_exec_child.c \
				$(SRC_DIR)/command_exec.c \
				$(SRC_DIR)/command_table.c \
				$(SRC_DIR)/env.c \
				$(SRC_DIR)/env_expand.c \
				$(SRC_DIR)/error.c \
				$(SRC_DIR)/ft_read.c \
				$(SRC_DIR)/ft_strcpy_until.c \
				$(SRC_DIR)/get_prompt.c \
				$(SRC_DIR)/malloc.c \
				$(SRC_DIR)/path.c \
				$(SRC_DIR)/redirection.c \
				$(SRC_DIR)/redirection_apply.c \
				$(SRC_DIR)/signals.c \
				$(SRC_DIR)/state.c \
				$(SRC_DIR)/str.c \
				$(SRC_DIR)/str_is.c \
				$(SRC_DIR)/str_skip.c \
				$(SRC_DIR)/token.c \
				$(SRC_DIR)/token_expand.c \
				$(SRC_DIR)/token_free.c \
				$(SRC_DIR)/token_sanitize.c \
				$(SRC_DIR)/token_type.c \
				$(SRC_DIR)/token_validate.c \

MAIN_SRCS	= 	$(SRC_DIR)/main.c $(SRC)
TEST_SRCS	= 	$(SRC_DIR)/tests.c \
				$(SRC_DIR)/tests_token.c \
				$(SRC_DIR)/tests_command_table.c \
				$(SRC)

CC 			= gcc
BREW_DIR 	= /Users/${USER}/.brew/opt
# BREW_DIR 	= /usr/local/opt
INCLUDES	= -I include -I libft -I${BREW_DIR}/readline/include
CFLAGS 		= -Wall -Werror -Wextra $(INCLUDES)
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
	@$(CC) $(CFLAGS) $(INCLUDES) $(TESTS_OBJS) libft/libft.a -lreadline -L${BREW_DIR}/readline/lib -o unit_test_$(NAME)
	@echo "\n\033[92m"-------------\\n👌 TESTS COMPILED 👌\\n-------------\\n"\033[0m\n"
	@echo
	@./unit_test_$(NAME)

clean:
	@clear
	@echo "\n\033[31m"-------------------\\n💣 DELETED FILES 💣\\n-------------------\\n"\033[0m\n"
	@rm -f $(OBJECTS) $(TESTS_OBJS)

fclean: clean
	@make fclean -C ./libft
	@rm -rf $(NAME)
	@rm -rf unit_test_$(NAME)
	@rm -rf minishell
	@rm -rf libft.a

re: fclean all

.PHONY: all clean re test
