NAME = main

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS_DIR = objs/
SRCS_DIR = srcs/

FILES = main.cpp

SRCS = $(addprefix $(SRCS_DIR), $(FILES))
OBJS = $(addprefix $(OBJS_DIR), $(FILES:.cpp=.o))

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	@echo "Cleaning: $(OBJS_DIR)"
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)
	@echo "Cleaning the .replace files"
	@rm -f *.replace

fclean: clean
	@echo "Cleanin: $(NAME)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re