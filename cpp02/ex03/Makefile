CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
SRC = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJ = $(SRC:.cpp=.o)
NAME = bsp

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
.SECONDARY: $(OBJ)