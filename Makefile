# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/05 12:09:31 by chael-ha          #+#    #+#              #
#    Updated: 2021/07/15 17:20:49 by chael-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC =	src/ft_putstr_fd.c\
	src/ft_strdup.c\
	src/ft_strjoin.c\
	src/ft_strlen.c\
	src/ft_strncmp.c\
	src/ft_substr.c\
	src/pipex.c\
	src/free_incase_ofleak.c\
	src/ft_split.c\
	src/argv1_neg.c\
	src/argv4_neg.c\
	src/cmd_is_known.c\
	src/access_denied.c\
	src/free_tab2dim.c\
	src/join_paths.c\

OBJ = $(SRC:.c=.o)
INCLUDES = pipex.h
FLAGS = -Wall -Wextra -Werror

all : $(NAME)
	
$(NAME) : $(OBJ) $(INCLUDES)
	gcc $(FLAGS) $(SRC) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all