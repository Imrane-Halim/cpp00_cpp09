CXXFLAGS = -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98 -g3
CXX = c++
SRC = main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp DiamondTrap.cpp
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