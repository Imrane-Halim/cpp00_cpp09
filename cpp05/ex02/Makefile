CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
CXX = c++
SRC = main.cpp Bureaucrat.cpp ShrubberyCreationForm.cpp AForm.cpp\
		RobotomyRequestForm.cpp
OBJ = $(SRC:.cpp=.o)
NAME = bureaucrat

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