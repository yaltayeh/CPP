NAME = brain

FILES = main.cpp		\

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OFILES = ${FILES:%.cpp=%.o}

all: $(NAME)

$(NAME): $(OFILES)
	$(CXX) $^ -o $@

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
