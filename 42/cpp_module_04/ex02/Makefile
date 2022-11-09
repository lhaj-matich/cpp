NAME=ex02
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
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
