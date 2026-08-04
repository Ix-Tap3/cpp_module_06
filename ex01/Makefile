NAME = Serializer
CC = c++
FLAGS = -g -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp Serializer.cpp
OBJS_DIR = objs
OBJS = ${SRCS:%.cpp=$(OBJS_DIR)/%.o}

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@ 

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
