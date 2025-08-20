NAME = bsp

CC = c++
CFLAGS = -Wall -Wextra -Werror -g
CPPFLAGS = -IMLX42/include 

FILES = main.cpp	\
		Fixed.cpp	\
		Point.cpp	\
		bsp.cpp		\

OFILES = ${FILES:%.cpp=%.o}

all: $(NAME)

$(NAME): $(OFILES)
	$(CC)  $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
