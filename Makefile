# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/05 12:09:31 by chael-ha          #+#    #+#              #
#    Updated: 2021/07/12 11:20:35 by chael-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC =	src/ft_putstr_fd.c\
	src/ft_strdup.c\
	src/ft_strjoin.c\
	src/ft_strlen.c\
	src/ft_strncmp.c\
	src/ft_substr.c\
	src/main.c\
	src/ft_split.c\
	
OBJ = $(SRC:.c=.o)
INCLUDES = pipex.h
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

#$(NAME) : $(OBJ) $(INCLUDES)
	
$(NAME) : $(OBJ) $(INCLUDES)
	gcc $(FLAGS) $(SRC) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all