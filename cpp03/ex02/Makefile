CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
SRC = main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp
OBJ = $(SRC:.cpp=.o)
NAME = clap

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