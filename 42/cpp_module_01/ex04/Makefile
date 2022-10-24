# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 15:50:02 by ochoumou          #+#    #+#              #
#    Updated: 2022/10/24 15:50:03 by ochoumou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=replace
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean all