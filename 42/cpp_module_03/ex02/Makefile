# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 12:09:58 by ochoumou          #+#    #+#              #
#    Updated: 2022/11/05 12:09:59 by ochoumou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ScavTrap
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp main.cpp
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

re: fclean all