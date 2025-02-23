SRC = AForm.cpp Bureaucrat.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp intern.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

NAME = Fixed

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp intern.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
