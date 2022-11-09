NAME=bureaucrat
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = Bureaucrat.hpp
SRC = main.cpp Bureaucrat.cpp
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
