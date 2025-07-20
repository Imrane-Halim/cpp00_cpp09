CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)
NAME = bank

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean