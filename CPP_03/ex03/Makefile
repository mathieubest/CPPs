NAME = main

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS_DIR = objs/
SRCS_DIR = src/

FILES = main.cpp \
		ClapTrap.cpp \
		DiamondTrap.cpp \
		FragTrap.cpp \
		ScavTrap.cpp

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

fclean: clean
	@echo "Cleaning: $(NAME)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re