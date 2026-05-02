NAME = main
WRONG_NAME = wrong_main

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes

OBJS_DIR = objs/
SRCS_DIR = src/

FILES = main.cpp \
		Animal.cpp \
		Cat.cpp \
		Dog.cpp

WRONG_FILES = main_wrong.cpp \
			WrongAnimal.cpp \
			WrongCat.cpp

SRCS = $(addprefix $(SRCS_DIR), $(FILES))
OBJS = $(addprefix $(OBJS_DIR), $(FILES:.cpp=.o))

WRONG_SRCS = $(addprefix $(SRCS_DIR), $(WRONG_FILES))
WRONG_OBJS = $(addprefix $(OBJS_DIR), $(WRONG_FILES:.cpp=.o))

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(WRONG_NAME): $(WRONG_OBJS)
	@$(CC) $(CFLAGS) -o $(WRONG_NAME) $(WRONG_OBJS)

all: $(NAME)

wrong: $(WRONG_NAME)

clean:
	@echo "Cleaning: $(OBJS_DIR)"
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "Cleaning: $(NAME)"
	@rm -f $(NAME)
	@rm -f $(WRONG_NAME)

re: fclean all

.PHONY: all clean fclean re