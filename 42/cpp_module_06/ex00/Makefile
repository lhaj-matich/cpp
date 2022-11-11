NAME=convert
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = convertNumber.hpp
SRC = main.cpp convertNumber.cpp utils.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp $(HEADER)
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
