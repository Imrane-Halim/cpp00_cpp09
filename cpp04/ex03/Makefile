CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 #-fsanitize=address
CXX = c++
SRC =	main.cpp AMateria.cpp Character.cpp Ice.cpp Cure.cpp \
		MateriaSource.cpp
OBJ = $(SRC:.cpp=.o)
NAME = interface

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