CXXFLAGS = -Wall -Wextra -Werror
CXX = c++
SRC = main.cpp RPN.cpp
OBJ = $(SRC:.cpp=.o)
NAME = RPN

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
.SECONDARY: $(OBJ)