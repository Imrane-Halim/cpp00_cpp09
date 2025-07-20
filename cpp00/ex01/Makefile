CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
SRC = Contact.cpp main.cpp PhoneBook.cpp
OBJ = $(SRC:.cpp=.o)
NAME = phonebook

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean