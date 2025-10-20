NAME = Bureau

FILES = main.cpp		\
		Bureaucrat.cpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -MMD -std=c++98

OFILES = ${FILES:%.cpp=%.o}
DFILES = ${OFILES:%.o=%.d}

all: $(NAME)

-include $(DFILES)

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
