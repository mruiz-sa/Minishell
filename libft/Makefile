# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 19:11:27 by mruiz-sa          #+#    #+#              #
#    Updated: 2022/04/19 12:19:07 by mruiz-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FUNCTIONS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_memset.c	ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
			ft_strncmp.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_bzero.c \
			ft_memcpy.c ft_strnstr.c ft_atoi.c ft_memmove.c ft_memchr.c \
			ft_memcmp.c ft_strdup.c ft_calloc.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c ft_strtrim.c \
			ft_itoa.c ft_strmapi.c ft_striteri.c ft_split.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

OBJECTS = $(FUNCTIONS:.c=.o)

BONUS_OBJETCS = $(BONUS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJECTS)
		ar rc $(NAME) $(OBJECTS)

$(OBJECTS): $(FUNCTIONS)
		gcc $(CFLAGS) -c $(FUNCTIONS)

$(BONUS_OBJECTS): $(FUNCTIONS) $(BONUS)
		gcc $(CFLAGS) -c $(FUNCTIONS) $(BONUS)
		
bonus: $(OBJECTS) $(BONUS_OBJETCS)
		ar rc $(NAME) $(OBJECTS) $(BONUS_OBJETCS)
clean:
		@rm -f $(OBJECTS) $(BONUS_OBJETCS)

fclean: clean
		@rm -f $(OBJECTS) $(BONUS_OBJETCS) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus