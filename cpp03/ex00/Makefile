NAME = wall_e


FILES = main.cpp	\
		ClapTrap.cpp	\

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

OFILES = ${FILES:%.cpp=%.o}

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
