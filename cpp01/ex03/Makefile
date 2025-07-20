CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
SRC = main.cpp Weapon.cpp HumanB.cpp HumanA.cpp
OBJ = $(SRC:.cpp=.o)
NAME = fight

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