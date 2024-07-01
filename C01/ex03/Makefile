SRC = HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp \
		main.cpp

OBJ = $(SRC:.cpp=.o)

NAME = Weapon

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Weapon.hpp HumanB.hpp HumanA.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re