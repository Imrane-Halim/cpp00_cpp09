CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
CXX = c++
SRC =	main.cpp AAnimal.cpp Dog.cpp Cat.cpp \
		WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJ = $(SRC:.cpp=.o)
NAME = animal

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
.SECONDARY: $(OBJ)